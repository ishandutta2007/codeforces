#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cerr<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 42 , md = 1e9 + 7 , inf = 2e16;

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

bitset<maxn> dp[maxn][maxn][maxn];
ll o[maxn] , par[maxn][maxn][maxn][maxn];
char c[maxn][maxn][maxn][maxn];

void solve(){
	ll n , a , b;
	string s;
	cin>>n>>a>>b>>s;
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j <= i + 1 ; j++){
			for(ll k = 0 ; k < a ; k++){
				for(ll q = 0 ; q < b ; q++){
					dp[i][j][k][q] = false;
				}
			}
		}
	}
	for(ll i = 0 ; i < n ; i++){
		o[i] = s[i] - '0';
	}
	dp[0][0][0][o[0] % b] = true; c[0][0][0][o[0] % b] = 'B';
	dp[0][1][o[0] % a][0] = true; c[0][1][o[0] % a][0] = 'R';
	for(ll i = 0 ; i < n - 1 ; i++){
		for(ll j = 0 ; j <= i + 1 ; j++){
			for(ll k = 0 ; k < a ; k++){
				for(ll q = 0 ; q < b ; q++){
					if(!dp[i][j][k][q]) continue;
					ll h = (10 * k + o[i + 1]) % a;
					dp[i + 1][j + 1][h][q] = true;
					par[i + 1][j + 1][h][q] = k;
					c[i + 1][j + 1][h][q] = 'R';
					h = (10 * q + o[i + 1]) % b;
					dp[i + 1][j][k][h] = true; 
					par[i + 1][j][k][h] = q;
					c[i + 1][j][k][h] = 'B';
				}
			}
		}
	}
	ll ans = n , ind = -1;
	for(ll j = 1 ; j < n ; j++){
		if(dp[n - 1][j][0][0]){
			if(ans > abs(n - 2 * j)){
				ind = j;
				ans = abs(n - 2 * j);
			}
		}
	}
	if(ind == -1){
		cout<<"-1\n";
		return;
	}
	string h;
	ll k = 0 , q = 0 , j = ind;
	for(ll i = n - 1 ; i >= 0 ; i--){
		h += c[i][j][k][q];
//		cout<<i<<' '<<j<<' '<<k<<' '<<q<<'\n';
		if(c[i][j][k][q] == 'R'){
			k = par[i][j][k][q];
			j--;
		} else {
			q = par[i][j][k][q];
		}
	}
	reverse(all(h));
	cout<<h<<'\n';
	return;	
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T;
	cin>>T; 
	while(T--) solve();
	return 0;
}