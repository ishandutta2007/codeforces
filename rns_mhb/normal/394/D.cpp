#include <stdio.h>
#include <algorithm>
#define min(a, b) ((a)<(b)?(a):(b))
#define max(a, b) ((a)>(b)?(a):(b))
#define N 1010

using namespace std;

int a[N];
int b[N];
const int inf=100000000;

int main() {
	int n, i, ans=inf, step, Min, Max, tmp, S, Mx, Mn;
//	freopen("D.in", "r", stdin);
	scanf("%d", &n);
	for (i=1; i<=n; i++) scanf("%d", a+i);
	sort(a+1, a+n+1);
	for (step=0; step<=20000; step++) {
		Min=Max=0;
		for (i=2; i<=n; i++) {
			b[i]=a[1]+step*(i-1);
			Min=min(b[i]-a[i], Min);
			Max=max(b[i]-a[i], Max);
			if (Max+1>ans*2) break;
		}
		if (i<=n) break;
		tmp=(Max-Min+1)/2;
		if (ans>tmp) ans=tmp, S=step, Mx=Max, Mn=Min;
	}
	printf("%d\n", ans);
	printf("%d %d\n", a[1]+ans-Mx, S);
}