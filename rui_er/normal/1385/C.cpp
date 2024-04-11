//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int T, n, a[200005];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i=1;i<=n;i++) {
			scanf("%d", &a[i]);
		}
		int k = n - 1;
		for(int i=n-1;i>=1;i--,k=i) {
			if(a[i] < a[i+1]) {
				break;
			}
		}
//		printf("k=%d\n", k);
		if(!k){
			puts("0");
			continue;
		}
		for(int i=k;i>=1;i--,k=i) {
			if(i == n) {
				continue;
			}
			if(a[i] > a[i+1]) {
				break;
			}
		}
		printf("%d\n", k);
	}
	return 0;
}