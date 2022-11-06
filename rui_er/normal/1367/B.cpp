//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int T, n, a[45], tot1, tot2;

void init() {
	n = tot1 = tot2 = 0;
	memset(a, 0, sizeof(a));
}

int main() {
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d", &n);
		for(int i=0;i<n;i++) {
			scanf("%d", &a[i]);
			if(a[i] % 2 != i % 2) {
				if(i & 1) {
					++tot1;
				}
				else {
					++tot2;
				}
			}
		}
		if(tot1 != tot2) {
			puts("-1");
		}
		else {
			printf("%d\n", tot1);
		}
	}
	return 0;
}