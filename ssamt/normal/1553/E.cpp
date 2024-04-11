#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>
#include <algorithm>

int main() {
	int h, i, j, k;
	int t, n, m;
	std::vector<int> answer;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d %d", &n, &m);
		answer.clear();
		int p[n];
		for(i=0; i<n; i++) {
			scanf("%d", &p[i]);
			p[i]--;
		}
		int count[n];
		memset(count, 0, sizeof(count));
		for(i=0; i<n; i++) {
			count[(n+p[i]-i)%n]++;
		}
		std::vector<int> pos;
		for(i=0; i<n; i++) {
			if(count[i] >= n-2*m) {
				pos.push_back(i);
				//printf("pos:%d\n", i);
			}
		}
		for(i=0; i<pos.size(); i++) {
			int shift = pos[i];
			int p2[n];
			for(j=0; j<n; j++) {
				p2[(j+shift)%n] = p[j];
			}
			int check[n];
			int change = 0;
			memset(check, 0, sizeof(check));
			for(j=0; j<n; j++) {
				if(!check[j]) {
					int chain;
					for(k=j, chain=1; p2[k] != j; k=p2[k], chain++) {
						check[k] = 1;
					}
					check[k] = 1;
					change += chain-1;
					//printf("%d %d %d\n", j, k, chain);
				}
			}
			if(change <= m) {
				answer.push_back((n-shift)%n);
			}
		}
		sort(answer.begin(), answer.end());
		printf("%d ", answer.size());
		for(i=0; i<answer.size(); i++) {
			printf("%d ", answer[i]);
		}
		printf("\n");
	}
}