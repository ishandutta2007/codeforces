#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
	long long i, j, k;
	int t;
	int saven;
	int n;
	int m;
	int temp;
	int answer;
	scanf("%d", &t);
	for(i=0; i<t; i++) {
		scanf("%d %d", &n, &m);
		saven = n;
		if(n > m) {
			printf("%d\n", 0);
			continue;
		}
		for(j=30; j>=0; j--) {
			if(!(n&(1<<j))) {
				temp = n|(1<<j);
				if(temp <= m) {
					n = temp;
				}
				else if(temp > m) {
					answer = temp^saven;
				}
			}
		}
		printf("%d\n", answer);
	}
}