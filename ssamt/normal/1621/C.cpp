#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		int answer[n];
		for(i=0; i<n; i++) {
			answer[i] = -1;
		}
		for(i=0; i<n; i++) {
			if(answer[i] == -1) {
				printf("? %d\n", i+1);
				fflush(stdout);
				int init;
				scanf("%d", &init);
				init--;
				int now = init;
				while(true) {
					printf("? %d\n", i+1);
					fflush(stdout);
					int next;
					scanf("%d", &next);
					next--;
					answer[now] = next;
					if(next == init) {
						break;
					}
					now = next;
				}
			}
		}
		printf("! ");
		for(i=0; i<n; i++) {
			printf("%d ", answer[i]+1);
		}
		printf("\n");
		fflush(stdout);
	}
}