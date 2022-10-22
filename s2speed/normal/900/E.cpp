#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#define gcd __gcd 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
 
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

ll dp[MAX_N] , ft[MAX_N] , pr[MAX_N] , pd[MAX_N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n , t;
	string s;
	cin>>n>>s>>t;
	if(t == 1){
		ll ans = 0;
		for(int i = 0 ; i < n ; i++){
			ans += (s[i] == '?');
		}
		cout<<ans<<'\n';
		return 0;
	}
	if(t > n){
		cout<<"0\n";
		return 0;
	}
	ll x = -1 , y = -1;
	char a = 'a' , b = 'b';
	if(t % 2){
		a = 'b';
		b = 'a';
	}
	for(int i = 0 ; i < n ; i++){
		ft[i] = -1;
	}
	for(int i = 1 ; i < n ; i += 2){
		if(s[i - 1] == b){
			x = i - 1;
		}
		if(s[i] == a){
			y = i;
		}
		if(max(x , y) <= i - t){
			ft[i] = 0;
		}
	}
	x = -1; y = -1;
	for(int i = 0 ; i < n ; i += 2){
		if(s[i] == a){
			y = i;
		}
		if(i == 0){
			continue;
		}
		if(s[i - 1] == b){
			x = i - 1;
		}
		if(max(x , y) <= i - t){
			ft[i] = 0;
		}
	}
	dp[0] = 0;
	for(int i = 1 ; i < n ; i++){
		dp[i] = dp[i - 1];
		if(ft[i] == 0){
			if(i == t - 1){
				dp[i] = 1;
			} else {
				dp[i] = dp[i - t] + 1;
			}
			ft[i] = dp[i];
		}
	}
	ll cnt = 0;
	x = 0; y = t - 1;
	for(int i = 0 ; i < n ; i++){
		pd[i] = 0;
	}
	for(int i = 0 ; i < y ; i++){
		cnt += (s[i] == '?');
	}
	while(y < n){
		cnt += (s[y] == '?');
		pd[y] = pd[y - 1];
		if(dp[y] > dp[y - 1]){
			if(y == t - 1){
				pd[y] = cnt;
			} else {
				pd[y] = pd[y - t] + cnt;
			}
		} else {
			if(ft[y] != -1){
				pd[y] = min(pd[y] , pd[y - t] + cnt);
			}
		}
		cnt -= (s[x] == '?');
		x++;
		y++;
	}
	cout<<pd[n - 1]<<'\n';
	return 0;
}