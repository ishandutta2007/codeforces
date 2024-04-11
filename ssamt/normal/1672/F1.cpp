#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int count[n+1] = {};
		vector<int> order[n];
		for(i=0; i<n; i++) {
			order[count[a[i]]].push_back(i);
			count[a[i]]++;
		}
		int b[n];
		for(i=0; i<n; i++) {
			sort(order[i].begin(), order[i].end(), [&](int first, int second) {
				return a[first] < a[second];
			});
			if(!order[i].empty()) {
	 			b[order[i][0]] = a[order[i].back()];
				for(j=1; j<order[i].size(); j++) {
					b[order[i][j]] = a[order[i][j-1]];
				}
			}
		}
		for(i=0; i<n; i++) {
			printf("%d ", b[i]);
		}
		printf("\n");
	}
}