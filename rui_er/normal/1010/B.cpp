//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int m, n, p[35];

int main() {
	scanf("%d%d", &m, &n);
	for(int i=0;i<n;i++) {
		printf("1\n");
		fflush(stdout);
		int _;
		scanf("%d", &_);
		if(!_) return 0;
		else if(_ == 1) p[i] = 1;
		else p[i] = -1;
	}
	int l = 2, r = m, rnds = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		printf("%d\n", mid);
		fflush(stdout);
		int _;
		scanf("%d", &_);
		_ *= p[rnds%n];
		rnds = (rnds + 1) % n;
		if(_ == 0) break;
		else if(_ == 1) l = mid + 1;
		else r = mid - 1;
	}
	return 0;
}