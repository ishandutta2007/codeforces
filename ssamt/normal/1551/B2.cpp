#include <stdio.h>
#include <vector>

int main() {
	int h, i, j;
	int t, n, k;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d %d", &n, &k);
		int cur = 1;
		int a[n];
		std::vector<int> count[n+1];
		std::vector<int> add;
		int answer[n];
		for(i=0; i<n; i++) {
			answer[i] = 0;
		}
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
			count[a[i]].push_back(i);
		}
		for(i=1; i<=n; i++) {
			if(count[i].size() >= k) {
				for(j=0; j<k; j++) {
					add.push_back(count[i][j]);
				}
			} else {
				for(j=0; j<count[i].size(); j++) {
					add.push_back(count[i][j]);
				}
			}
		}
		for(i=0; i<k*(add.size()/k); i++) {
			answer[add[i]] = i%k+1;
		}
		for(i=0; i<n; i++) {
			printf("%d ", answer[i]);
		}
		printf("\n");
	}
}