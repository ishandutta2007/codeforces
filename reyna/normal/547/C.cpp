//In the name of God
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int Maxn = 1e6 + 9;
const ll Mod = 1e9 + 7;
ll gcd(ll a,ll b){ return (a < b)?gcd(b,a):(b?(gcd(b,a%b)):a); }
ll lcm(ll a,ll b){ return (a / gcd(a,b)) * b; }
ll pw(ll a,ll b){ return b?(pw((a * a) % Mod,b >> 1) * (b & 1?a:1)) % Mod:1; }
ll inv(ll a){ return pw(a,Mod - 2); }
ll is[Maxn],sieve[Maxn];
ll in[Maxn],arr[Maxn];
ll cnt[Maxn];
vector<int> primes[Maxn];
ll ans = 0;
void f(int x){
	int p;
	if(in[x]) p = -1;
	else p = 1;
	in[x] ^= 1;
	x = arr[x];
	for(int mask = 0;mask < (1 << primes[x].size());mask++){
		int cur = 1;
		for(int i = 0; i < primes[x].size();i++)
			if(mask & (1 << i))
				cur *= primes[x][i];
		ans -= ((cnt[cur] * (cnt[cur] - 1)) / 2) * is[cur];
		cnt[cur] += p;
		ans += ((cnt[cur] * (cnt[cur] - 1)) / 2) * is[cur];
	}
	return;
}
int main(){
	is[1] = 1;
	for(int i = 2; i < Maxn;i++) is[i] = 1;
	for(int i = 2; i < Maxn;i++){
		if(!sieve[i]){
			for(int j = i; j < Maxn; j += i){
				sieve[j] = 1,primes[j].push_back(i);
				if(is[j] == -1) is[j] = 1;
				else is[j] = -1;
			}
		}
	}
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i = 0; i < n;i++) scanf("%d",&arr[i]);
	for(int i = 0; i < q;i++){
		int x;
		scanf("%d",&x);
		f(--x);
		printf("%I64d\n",ans);
	}
	return 0;
}