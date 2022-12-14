//In the name of God
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int Maxn = 5e6 + 9;
const ll Mod = 1e9 + 7;
ll pw(ll a,ll b){ return b?(pw((a * a) % Mod,b >> 1) * (b & 1?a:1))%Mod:1; }
ll gcd(ll a,ll b){ return (a < b)?gcd(b,a):(b?gcd(b,a%b):a); }
ll inv(ll a){ return pw(a,Mod-2); }
ll dp[Maxn];
int sieve[Maxn];
int arr[Maxn];
int main(){
	for(int i = 2; i < Maxn;i++){
		if(!sieve[i]){
			for(int j = i; j < Maxn;j+=i){
				int x = j;
				sieve[j] = 1;
				while(x % i == 0) x /= i,dp[j]++;
			}
		}
	}
	for(int i = 2; i < Maxn;i++) dp[i] += dp[i-1];
//	for(int i = 2; i < Maxn;i++){
//		int x = i;
//		ll ans = 0;
//		for(int j = 2; j * j <= x;j++){
//			while(x % j == 0) x/=j,ans++;
//		}
//		if(x - 1) ans++;
//		dp[i] = dp[i-1] + ans;
//	}
	int tc;
	cin >> tc;
	while(tc--){
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%I64d\n",dp[a]-dp[b]);
	}
	return 0;
}