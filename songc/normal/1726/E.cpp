#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define MOD 998244353
#define INF (1ll<<62)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int TC, N;
LL ans;
LL D[303030], DD[303030];
LL F[303030], I[303030];

LL Pow(LL x, LL y){
	if (!y) return 1;
	LL z = Pow(x, y/2);
	if (y&1) return z*z%MOD*x%MOD;
	return z*z%MOD;
}
LL inv(LL x){return Pow(x, MOD-2);}

LL Comb(int n, int r){return F[n] * I[r] % MOD * I[n-r] % MOD;}

LL f(int n, int r){return Comb(n-2*r, 2*r);}

int main(){
	scanf("%d", &TC);
	F[0] = 1;
	for (int i=1; i<=300000; i++) F[i] = F[i-1] * i % MOD;
	I[300000] = inv(F[300000]);
	for (int i=299999; i>0; i--) I[i] = I[i+1] * (i+1) % MOD;
	I[0] = 1;
	D[0] = D[1] = 1;
	for (int i=2; i<=300000; i++) D[i] = (D[i-1] + D[i-2]*(i-1))%MOD;
	DD[0] = DD[1] = 1;
	for (int i=1; i<=300000; i++) DD[i] = (DD[i-1] + DD[i-2] * (2*i-2) % MOD * (2*i - 3))%MOD;
	while (TC--){
		scanf("%d", &N);
		ans = 0;
		for (int i=0; 4*i<=N; i++){
			LL s = f(N, i) * DD[i] % MOD;
			s = s * Pow(2, i) % MOD;
			s = s * D[N - 4*i] % MOD;
			ans = (ans + s) % MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}