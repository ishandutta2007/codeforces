#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
	long long i, j, k;
	int t;
	int n, m;
	char s[100000];
	scanf("%d", &t);
	for(i=0; i<t; i++) {
		scanf("%d %d", &n, &m);
		int answer[m];
		for(j=0; j<m; j++) {
			answer[j] = 0;
		}
		for(j=0; j<n; j++) {
			scanf("%s", s);
			for(k=0; k<m; k++) {
				answer[k] += s[k];
			}
		}
		for(j=0; j<n-1; j++) {
			scanf("%s", s);
			for(k=0; k<m; k++) {
				answer[k] -= s[k];
			}
		}
		for(j=0; j<m; j++) {
			s[j] = answer[j];
		}
		s[m] = '\0';
		printf("%s\n", s);
	}
}