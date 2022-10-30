#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		int x, y;
		vector<vector<int>> p;
		for(i=0; i<3; i++) {
			scanf("%d %d", &x, &y);
			p.push_back({y, x});
		}
		sort(p.begin(), p.end());
		if(p[1][0] == p[2][0]) {
			printf("%d\n", abs(p[1][1]-p[2][1]));
		} else {
			printf("0\n");
		}
	}
}