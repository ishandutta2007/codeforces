#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second

using namespace std;
using LL = long long;
using pii = pair<int, int>;

const int NN = 1e6+10;

int a[NN], flag[NN];
LL b[NN], c[NN], d[NN], C[NN], D[NN];
LL t=0, ans=0x3f3f3f3f3f3f3f3fll;
int n;

inline LL calc(LL f) {
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

		LL r=0x3f3f3f3f3f3f3f3fll;
		for(int k=i; k<=j; k++) r=min(r, c[k]+d[k]);
		ans+=r;
		if(ans>=::ans) return ans;
		b[j]=t;
		while(j<=n && b[j] == 0) j++;

	}
	return ans;
}

int main() {
#ifdef KN
	freopen("C.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif // KN
	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d", a+i), t+=a[i];
	if(t <= 1ll) {
		puts("-1");
		return 0;
	}
	LL tt=t;
	for(int i=2; (LL)i*i<=t; i++) if(flag[i] == 0) {
		if(t%i == 0) {
			ans=min(ans, calc(i));
			while(tt%i == 0) tt/=i;
		}
		if((LL)i*i<NN) {
			for(int j=i*i; j<NN; j+=i) flag[j]=1;
		}
	}
	ans=min(ans, calc(tt));
	cout<<ans<<endl;
	return 0;
}