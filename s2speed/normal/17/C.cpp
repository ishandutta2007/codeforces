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

const ll maxn = 162 , md = 51123987 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

inline ll tav(ll n , ll k){
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

string s;
vector<int> t;

int pd[maxn][maxn / 3][maxn / 3] , ps[maxn][maxn / 3][maxn / 3] , dp[maxn][maxn / 3][maxn / 3] , pr[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(pd , 0 , sizeof(pd));
	memset(dp , 0 , sizeof(dp));
	memset(ps , 0 , sizeof(ps)); for(int j = 0 ; j < maxn ; j++) ps[j][0][0] = 1;
	int n;
	cin>>n>>s;
	t.push_back(s[0] - 'a');
	for(int i = 1 ; i < n ; i++){
		if(s[i] == s[i - 1]) continue;
		t.push_back(s[i] - 'a');
	}
	int m = sze(t) , lm = (n + 2) / 3;
	int ls[] = {-1 , -1 , -1};
	for(int i = 0 ; i < m ; i++){
		int h = t[i];
		pr[i] = ls[h] + 1;
		ls[h] = i;
	}
	for(int i = 0 ; i < n ; i++){
		for(int q = 0 ; q <= lm ; q++){
			for(int w = 0 ; w <= lm ; w++){
				for(int j = 1 ; j <= m ; j++){
					int c = t[j - 1] , h;
					if(c == 0){
						if(!q) continue;
						h = ps[j - 1][q - 1][w];
						if(pr[j - 1] != 0){
							h -= ps[pr[j - 1]][q - 1][w];
							h %= md; h += (h < 0) * md;
						}
						dp[j][q][w] = h;
					}
					if(c == 1){
						if(!w) continue;
						h = ps[j - 1][q][w - 1];
						if(pr[j - 1] != 0){
							h -= ps[pr[j - 1]][q][w - 1];
							h %= md; h += (h < 0) * md;
						}
						dp[j][q][w] = h;
					}
					if(c == 2){
						h = ps[j - 1][q][w];
						if(pr[j - 1] != 0){
							h -= ps[pr[j - 1]][q][w];
							h %= md; h += (h < 0) * md;
						}
						dp[j][q][w] = h;
					}
				}
			}
		}
		for(int w = 0 ; w <= lm ; w++){
			for(int q = 0 ; q <= lm ; q++){
				for(int j = 1 ; j <= m ; j++){
					ll c = t[j - 1];
					if(c == 0){
						dp[j][q + 1][w] += pd[j][q][w];
					} else if(c == 1){
						dp[j][q][w + 1] += pd[j][q][w];
					} else {
						dp[j][q][w] += pd[j][q][w];
					}
					dp[j][q][w] %= md;
				}
			}
		}
		memcpy(pd , dp , sizeof(pd));
		memset(ps , 0 , sizeof(ps));
		memset(dp , 0 , sizeof(dp));
		for(int j = 1 ; j <= m ; j++){
			for(int w = 0 ; w <= lm ; w++){
				for(int q = 0 ; q <= lm ; q++){
					ps[j][q][w] = ps[j - 1][q][w] + pd[j][q][w]; ps[j][q][w] %= md;
				}
			}
		}
	}
	int ans;
	if(n % 3 == 0){
		ans = ps[m][lm][lm];
	} else if(n % 3 == 1){
		ans = ps[m][lm - 1][lm - 1] + ps[m][lm][lm - 1] + ps[m][lm - 1][lm];
		ans %= md;
	} else {
		ans = ps[m][lm][lm] + ps[m][lm - 1][lm] + ps[m][lm][lm - 1];
		ans %= md;
	}
	cout<<ans<<'\n';
	return 0;
}

/*
5
aabac
*/