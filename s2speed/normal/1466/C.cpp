#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define gcd __gcd 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
struct piii {
	int first , second , third;
};

const ll MAX_N = 2e5 + 20 , md = 1e9 + 7;
 
ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
		}
		n *= n;
		k /= 2;
	}
	return res;
}

int dp[MAX_N];

void solve(){
	string s;
	int n;
	cin>>s; n = s.size();
	dp[0] = 0;
	dp[1] = (s[1] == s[0]);
	for(int i = 2 ; i < n ; i++){
		int h , q;
		if(s[i] == s[i - 2]){
			h = dp[i - 1] + 1;
			if(i == 2){
				dp[i] = min(h , 1 + (s[i] == s[i - 1]));
				continue;
			}
			q = dp[i - 3] + 1 + (s[i] == s[i - 1]);
			if(s[i] != s[i - 1]){
				if(i > 2){
					if(s[i - 1] == s[i - 3]){
						if(i == 3){
							q = 2;
						} else {
							q = dp[i - 4] + 2;
						}
					}
				}
			}
			dp[i] = min(h , q);
		} else if(s[i] == s[i - 1]){
			dp[i] = dp[i - 2] + 1;
		} else {
			dp[i] = dp[i - 1];
		}
	}
	cout<<dp[n - 1]<<'\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}