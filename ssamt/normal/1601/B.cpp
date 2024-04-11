#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k;
	int t, n, m, q;
	scanf("%d", &n);
	int a[n+1], b[n+1];
	a[0] = 0;
	for(i=1; i<=n; i++) {
		scanf("%d", &a[i]);
	}
	b[0] = 0;
	for(i=1; i<=n; i++) {
		scanf("%d", &b[i]);
	}
	int visita[n+1] = {};
	int visitb[n+1] = {};
	visitb[n] = n;
	vector<int> to_visita{n};
	vector<int> to_visitb;
	int min_h = n;
	while(!visita[0] && !to_visita.empty()) {
		for(int h:to_visita) {
			//printf("%d ", h);
			for(i=max(0, h-min_h+1); i<=a[h]; i++) {
				visita[h-i] = visitb[h];
				to_visitb.push_back(h-i);
				min_h = h-i;
			}
		}
		//printf("\n");
		to_visita.clear();
		for(int h:to_visitb) {
			//printf("%d ", h);
			visitb[h+b[h]] = h;
			to_visita.push_back(h+b[h]);
		}
		//printf("\n");
		to_visitb.clear();
		/*for(i=0; i<=n; i++) {
			printf("%d ", visita[i]);
		}
		printf("\n");
		for(i=0; i<=n; i++) {
			printf("%d ", visitb[i]);
		}
		printf("\n");*/
	}
	if(visita[0]) {
		vector<int> path;
		for(i=0; i<n; i=visita[i]) {
			path.push_back(i);
		}
		printf("%d\n", path.size());
		for(i=path.size()-1; i>=0; i--) {
			printf("%d ", path[i]);
		}
		printf("\n");
	} else {
		printf("-1\n");
	}
}