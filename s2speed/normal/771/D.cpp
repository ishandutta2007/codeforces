#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cout<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 79 , md = 1e9 + 7 , inf = 2e16;

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

ll a[maxn] , dp[maxn][maxn][maxn][3] , b[maxn];
vector<ll> v[3];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , cnt[] = {0 , 0 , 0};
	string s;
	cin>>n>>s;
	for(ll i = 0 ; i < n ; i++){
		if(s[i] == 'V'){
			a[i] = 0;
		} else if(s[i] == 'K'){
			a[i] = 1;
		} else {
			a[i] = 2;
		}
		b[i] = cnt[a[i]]++;
		v[a[i]].push_back(i);
	}
	memset(dp , 63 , sizeof(dp));
	if(cnt[0]) dp[0][1][0][0] = 2 * v[0][0];
	if(cnt[1]) dp[0][0][1][1] = 2 * v[1][0];
	if(cnt[2]) dp[0][0][0][2] = 2 * v[2][0];
	for(ll i = 1 ; i < n ; i++){
		for(ll x = 0 ; x <= i + 1 ; x++){
			if(x > cnt[0]) continue;
			for(ll y = 0 ; x + y <= i + 1 ; y++){
				if(y > cnt[1]) continue;
				ll z = i + 1 - x - y;
				if(z > cnt[2]) continue;
				if(x){
					dp[i][x][y][0] = min(min(dp[i - 1][x - 1][y][0] , dp[i - 1][x - 1][y][1]) , dp[i - 1][x - 1][y][2]);
					ll h = v[0][x - 1];
					for(ll j = v[0][x - 1] ; j < n ; j++){
						if(a[j] == 1 && b[j] < y) h++;
						if(a[j] == 2 && b[j] < z) h++;
					}
					dp[i][x][y][0] += 2 * abs(i - h);
				}
				if(y){
					dp[i][x][y][1] = min(dp[i - 1][x][y - 1][1] , dp[i - 1][x][y - 1][2]);
					ll h = v[1][y - 1];
					for(ll j = v[1][y - 1] ; j < n ; j++){
						if(a[j] == 0 && b[j] < x) h++;
						if(a[j] == 2 && b[j] < z) h++;
					}
					dp[i][x][y][1] += 2 * abs(i - h);
				}
				if(z){
					dp[i][x][y][2] = min(min(dp[i - 1][x][y][0] , dp[i - 1][x][y][1]) , dp[i - 1][x][y][2]);
					ll h = v[2][z - 1];
					for(ll j = v[2][z - 1] ; j < n ; j++){
						if(a[j] == 0 && b[j] < x) h++;
						if(a[j] == 1 && b[j] < y) h++;
					}
					dp[i][x][y][2] += 2 * abs(i - h);
				}
			}
		}
	}
	ll ans = min(min(dp[n - 1][cnt[0]][cnt[1]][0] , dp[n - 1][cnt[0]][cnt[1]][1]) , dp[n - 1][cnt[0]][cnt[1]][2]) / 2;
	cout<<ans<<'\n';
	return 0;
}