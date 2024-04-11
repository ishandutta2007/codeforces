#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j, k;
	int a, b;
	int n, m;
	scanf("%d %d", &n, &m);
	int count = n;
	int larger[n+1];
	for(i=1; i<=n; i++) {
		larger[i] = 0;
	}
	for(i=0; i<m; i++) {
		scanf("%d %d", &a, &b);
		if(a < b) {
			larger[a]++;
			if(larger[a] == 1) {
				count--;
			}
		}
		else if(b < a) {
			larger[b]++;
			if(larger[b] == 1) {
				count--;
			}
		}
	}
	int q;
	int code;
	scanf("%d", &q);
	for(i=0; i<q; i++) {
		scanf("%d", &code);
		if(code == 1) {
			scanf("%d %d", &a, &b);
			if(a < b) {
				larger[a]++;
				if(larger[a] == 1) {
					count--;
				}
			}
			else if(b < a) {
				larger[b]++;
				if(larger[b] == 1) {
					count--;
				}
			}
		}
		else if(code == 2) {
			scanf("%d %d", &a, &b);
			if(a < b) {
				larger[a]--;
				if(larger[a] == 0) {
					count++;
				}
			}
			else if(b < a) {
				larger[b]--;
				if(larger[b] == 0) {
					count++;
				}
			}
		}
		else if(code == 3) {
			printf("%d\n", count);
		}
	}
}