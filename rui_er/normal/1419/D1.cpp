//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

int n, a[N];

int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	sort(a+1, a+1+n);
	printf("%d\n", (n-1)/2);
	int _1 = 0, _2 = n + 1;
	for(int i=1;i<=n;i++) {
		if(i&1) printf("%d ", a[--_2]);
		else printf("%d ", a[++_1]);
	}
	return 0;
}