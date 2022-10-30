#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &q);
	vector<int> a;
	int size = 500001;
	int g[size];
	for(i=0; i<size; i++) {
		g[i] = i;
	}
	vector<vector<int>> s;
	vector<int> answer;
	for(ql=0; ql<q; ql++) {
		scanf("%d", &k);
		s.push_back({k});
		if(k == 1) {
			scanf("%d", &in);
			s.back().push_back(in);
		} else {
			int x, y;
			scanf("%d %d", &x, &y);
			s.back().push_back(x);
			s.back().push_back(y);
		}
	}
	for(ql=q-1; ql>=0; ql--) {
		if(s[ql][0] == 1) {
			answer.push_back(g[s[ql][1]]);
		} else {
			g[s[ql][1]] = g[s[ql][2]];
		}
	}
	for(i=answer.size()-1; i>=0; i--) {
		printf("%d ", answer[i]);
	}
	printf("\n");
}