#include <bits/stdc++.h>

using namespace std;

vector<vector<long long>> turn(vector<int> &a, int m) {
	int i;
	vector<vector<long long>> answer;
	for(i=0; i<a.size(); i++) {
		int count = 1;
		while(a[i]%m == 0) {
			a[i] /= m;
			count *= m;
		}
		if(answer.empty() || answer.back()[0] != a[i]) {
			answer.push_back({a[i], count});
		} else {
			answer.back()[1] += count;
		}
	}
	return answer;
}

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d %d", &n, &m);
		vector<int> a;
		for(i=0; i<n; i++) {
			scanf("%d", &in);
			a.push_back(in);
		}
		scanf("%d", &n);
		vector<int> b;
		for(i=0; i<n; i++) {
			scanf("%d", &in);
			b.push_back(in);
		}
		if(turn(a, m) == turn(b, m)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}