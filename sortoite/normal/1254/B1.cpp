#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second

using namespace std;
using LL = long long;
using pii = pair<int, int>;

const int mod = 1e9+7;

int power(int a, int b, int ans=1) {
	for(; b; b>>=1, a=(LL)a*a%mod) if(b&1) ans=(LL)ans*a%mod;
	return ans;
}

const int NN = 1e6+10;

LL a[NN], b[NN], c[NN], d[NN], C[NN], D[NN];
int n;

LL calc(LL f) {
	if(f <= 1ll) return 0x3f3f3f3f3f3f3f3fll;
	for(int i=1; i<=n; i++) b[i]=a[i]%f;
	LL tmp=0, ans=0;
	for(int i=1, j=1; i<=n; i=j) {
		tmp=0;
		for(j=i; j<=n; j++) {
			tmp+=b[j];
			if(tmp>=f) break;
		}
		if(tmp == 0) break;
		LL t=tmp-f;
		b[j]=b[j]-t;

		c[i]=0;
		C[i]=b[i];
		for(int k=i+1; k<=j; k++) {
			c[k]=c[k-1]+C[k-1];
			C[k]=C[k-1]+b[k];
		}

		d[j]=0;
		D[j]=b[j];
		for(int k=j-1; k>=i; k--) {
			d[k]=d[k+1]+D[k+1];
			D[k]=D[k+1]+b[k];
		}

		b[j]=t;
		LL r=0x3f3f3f3f3f3f3f3fll;
		for(int k=i; k<=j; k++) r=min(r, c[k]+d[k]);
		ans+=r;
	}
	return ans;
}

int main() {
#ifdef KN
	freopen("C.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif // KN
	LL t=0, ans=0x3f3f3f3f3f3f3f3fll;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%I64d", a+i), t+=a[i];
	if(t <= 1ll) {
		puts("-1");
		return 0;
	}
	for(int i=1; (LL)i*i<=t; i++) {
		if(t%i == 0) {
			ans=min(ans, calc(i));
			ans=min(ans, calc(t/i));
		}
	}
	cout<<ans<<endl;
	return 0;
}