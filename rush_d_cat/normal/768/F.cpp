#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 200000 + 10;
LL fac[N],inv[N];
LL mpow(LL a, LL x){
	if(x==0)return 1;
	LL t=mpow(a,x>>1);
	if(x%2==0)return t*t%MOD;
	return t*t%MOD*a%MOD;
}
LL C(int x,int y){
	if(x<y||x<0||y<0)return 0;
	return fac[x]*inv[y]%MOD*inv[x-y]%MOD;
}
int f,w,h;
int solve(LL n,LL k,LL m) {
	if(n==0 && m==0) return 1;
	// x1+x2+....xn = m
	// xi >= k
	m = m - k * n;
	if (m < 0) return 0;
	return C(m + n - 1, n - 1);
}

LL solve() {
	LL ans=0;
	for(int i=0;i<=max(f,w);i++){
		// i, i
		LL tmp = 1LL * solve(i,h,w) * solve(i,1,f) % MOD;
		(ans += 2 * tmp)  %= MOD;
		//printf("i = %d, ans = %lld\n", i, ans);
		// i+1, i
		tmp = 1LL * solve(i+1,h,w) * solve(i,1,f) % MOD;
		ans = (ans + tmp) % MOD;
	//	printf("i = %d, ans = %lld\n", i, ans);
		// i, i+1
		tmp = 1LL * solve(i,h,w) * solve(i+1,1,f) % MOD;
		ans = (ans + tmp) % MOD;
	//	printf("i = %d, ans = %lld\n", i, ans);
	}
	return ans;	
}

int main() {
	fac[0]=1,inv[0]=1;
	for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%MOD;
	for(int i=1;i<N;i++)inv[i]=mpow(i,MOD-2);
	for(int i=1;i<N;i++)inv[i]=inv[i-1]*inv[i]%MOD;

	cin>>f>>w>>h; 
	if (f+w+h==0) return !printf("1\n");
	++h;
	
	LL A = solve();
	h = 1;
	LL B = solve();
	LL ans = A * mpow(B, MOD-2) % MOD;
	cout << ans << endl;
}