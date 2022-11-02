#include <stdio.h>
#include <set>
#define N 5010
#define M 32000

using namespace std;

int a[N];
int g[N], div[N];
int val[N], sum[N];
set <int> prime;
bool fl[M];
int p[N], cnt;
int u[M];

int gcd(int x, int y) {
	if (!y) return x;
	return gcd(y, x%y);
}

int main() {
	int n, m, i, j, k, b, tmp, ans;
	cnt=0;
	for (i=2; i*i<M; i++) if (!fl[i]) {
		for (j=i; j*i<M; j++) fl[i*j]=1;
	}
	for (i=2; i<M; i++) if (!fl[i]) p[++cnt]=i, u[i]=1;
//	freopen ("in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (i=1; i<=n; i++) scanf("%d", a+i);
	g[1]=a[1];
	for (i=2; i<=n; i++) g[i]=gcd(g[i-1], a[i]);
	prime.clear();
	for (i=1; i<=m; i++) {
		scanf("%d", &b);
		prime.insert(b);
		if (b<M) u[b]=-1;
	}
	div[n]=g[n];
	for (i=n-1; i; i--) div[i]=g[i]/g[i+1];
	sum[0]=0;
	for (i=1; i<=n; i++) {
		tmp=div[i];
		val[i]=0;
		for (j=1; j<=cnt && p[j]*p[j]<=tmp; j++) if (tmp%p[j]==0) {
			while (tmp%p[j]==0) tmp/=p[j], val[i]+=u[p[j]];
		}
		if (tmp>1) {
			if (prime.count(tmp)) val[i]--;
			else val[i]++;
		}
		sum[i]=sum[i-1]+val[i];
	}
	ans=0;
	for (i=1; i<=n; i++) {
		tmp=a[i];
		for (j=1; j<=cnt && p[j]*p[j]<=tmp; j++) if (tmp%p[j]==0) {
			while (tmp%p[j]==0) tmp/=p[j], ans+=u[p[j]];;
		}
		if (tmp>1) {
			if (prime.count(tmp)) ans--;
			else ans++;
		}
	}
	k=n;
	for (j=n; j; j--) {
		if (sum[k]-sum[j-1]<0) {
			ans-=(sum[k]-sum[j-1])*j;
			k=j-1;
		}
	}
	printf("%d\n", ans);
}