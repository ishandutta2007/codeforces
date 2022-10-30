#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, k, l;
	int t, n, m, q;
	scanf("%d", &t);
	for(int cl=0; cl<t; cl++) {
		scanf("%d", &n);
		vector<int> a(n);
		k = 0;
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
			if(a[i] > i+1) {
				k++;
			}
		}
		vector<vector<int>> p(n+1);
		for(i=0; i<n; i++) {
			if(a[i] == 0 || a[i] == n+1) {
				p[0].push_back(i+1);
			} else {
				p[a[i]].push_back(i+1);
			}
		}
		vector<int> answer;
		queue<int> to;
		to.push(0);
		while(!to.empty()) {
			int node = to.front();
			to.pop();
			int save = -1;
			for(i=0; i<p[node].size(); i++) {
				if(p[p[node][i]].empty()) {
					to.push(p[node][i]);
				} else {
					save = p[node][i];
				}
			}
			if(save != -1) {
				to.push(save);
			}
			answer.push_back(node);
		}
		printf("%d\n", k);
		for(i=1; i<answer.size(); i++) {
			printf("%d ", answer[i]);
		}
		printf("\n");
	}
}