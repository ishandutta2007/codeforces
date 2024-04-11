#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
struct plll { ll x , y , z; };
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e2 + 16 , md = 1e9 + 7 , inf = 2e17;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k >>= 1;
	}
	return res;
}

ll f[maxn] , upd[maxn][26] , dp[maxn][maxn][maxn];
plll par[maxn][maxn][maxn];
bitset<maxn> ch[maxn][maxn];
string a , b , c;
ll n , m , k;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	memset(dp , 0 , sizeof(dp));
	memset(par , -1 , sizeof(par));
	cin>>a>>b>>c;
	n = sze(a); m = sze(b); k = sze(c);
	ll cur = f[1] = 0;
	for(ll i = 2 ; i <= k ; i++){
		while(cur && c[cur] != c[i - 1]) cur = f[cur];
		if(c[cur] == c[i - 1]) cur++;
		f[i] = cur;
	}
	for(ll j = 0 ; j < 26 ; j++){
		upd[0][j] = ((c[0] - 'A') == j);
		for(ll i = 1 ; i < k ; i++){
			if(c[i] - 'A' == j){
				upd[i][j] = i + 1;
			} else {
				upd[i][j] = upd[f[i]][j];
			}
		}
	}
	if(a[0] == b[0]){
		dp[0][0][a[0] == c[0]] = 1;
		ch[0][0][a[0] == c[0]] = true;
	}
	for(ll j = 1 ; j < m ; j++){
		dp[0][j][0] = dp[0][j - 1][0];
		par[0][j][0] = par[0][j - 1][0];
		if(ch[0][j - 1][0]) par[0][j][0] = {0 , j - 1 , 0};
		dp[0][j][1] = dp[0][j - 1][1];
		par[0][j][1] = par[0][j - 1][1];
		if(ch[0][j - 1][1]) par[0][j][1] = {0 , j - 1 , 1};
		if(a[0] == b[j] && !dp[0][j][a[0] == c[0]]){
			dp[0][j][a[0] == c[0]] = 1;
			ch[0][j][a[0] == c[0]] = true;
		}
	}
	for(ll i = 1 ; i < n ; i++){
		dp[i][0][0] = dp[i - 1][0][0];
		par[i][0][0] = par[i - 1][0][0];
		if(ch[i - 1][0][0]) par[i][0][0] = {i - 1 , 0 , 0};
		dp[i][0][1] = dp[i - 1][0][1];
		par[i][0][1] = par[i - 1][0][1];
		if(ch[i - 1][0][1]) par[i][0][1] = {i - 1 , 0 , 1};
		if(a[i] == b[0] && !dp[i][0][b[0] == c[0]]){
			dp[i][0][b[0] == c[0]] = 1;
			ch[i][0][b[0] == c[0]] = true;
		}
		for(ll j = 1 ; j < m ; j++){
			for(ll q = 0 ; q < k ; q++){
				if(dp[i][j - 1][q] > dp[i - 1][j][q]){
					par[i][j][q] = par[i][j - 1][q];
					dp[i][j][q] = dp[i][j - 1][q];
					if(ch[i][j - 1][q]) par[i][j][q] = {i , j - 1 , q};
				} else {
					dp[i][j][q] = dp[i - 1][j][q];
					par[i][j][q] = par[i - 1][j][q];
					if(ch[i - 1][j][q]) par[i][j][q] = {i - 1 , j , q};
				}
			}
			if(a[i] != b[j]) continue;
			for(ll q = 0 ; q < k ; q++){
				ll h = upd[q][a[i] - 'A'];
				if(dp[i][j][h] < dp[i - 1][j - 1][q] + 1){
					dp[i][j][h] = dp[i - 1][j - 1][q] + 1;
					par[i][j][h] = par[i - 1][j - 1][q];
					if(ch[i - 1][j - 1][q]) par[i][j][h] = {i - 1 , j - 1 , q};
					ch[i][j][h] = true;
				}
			}
		}
	}
	ll ans = 0 , h = -1;
	for(ll i = 0 ; i < k ; i++){
		if(ans < dp[n - 1][m - 1][i]){
			ans = dp[n - 1][m - 1][i];
			h = i;
		}
	}
	if(!ans){
		cout<<"0\n";
		return 0;
	}
	plll p;
	if(ch[n - 1][m - 1][h]){
		p = {n - 1 , m - 1 , h};
	} else {
		p = par[n - 1][m - 1][h];
	}
	string s;
	while(p.x >= 0 && p.y >= 0){
		s += a[p.x];
		p = par[p.x][p.y][p.z];
	}
	reverse(all(s));
	cout<<s<<'\n';
	return 0;
}