//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;
const int N = 5e3+5, inf = 0x3f3f3f3f;

int n, a[N];

int f(int l, int r) {
//	printf("F(%d, %d)\n", l, r);
	if(l > r) return 0;
	if(l == r) return a[l] ? 1 : 0;
	int mi = inf, mi2 = 0;
	for(int i=l;i<=r;i++) {
		if(a[i] < mi) {
			mi = a[i];
			mi2 = i;
		}
	}
	int lst = l - 1, tmp = 0;
	for(int i=l;i<=r;i++) {
		a[i] -= mi;
//		printf("A[%d]: %d\n", i, a[i]);
		if(!a[i]) {
			tmp += f(lst+1, i-1);
			lst = i;
		}
	}
	tmp += f(lst+1, r);
	tmp += mi;
	return min(tmp, r-l+1);
}

int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	printf("%d\n", f(1, n));
	return 0;
}