#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<vector<int> > G(N);
	vector<int> indeg(N);
	for(int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b; --a, --b;
		G[b].push_back(a);
		++indeg[a];
	}
	priority_queue<int> que;
	for(int i = 0; i < N; ++i) {
		if(indeg[i] == 0) {
			que.push(i);
		}
	}
	vector<int> ans;
	while(!que.empty()) {
		int u = que.top(); que.pop();
		ans.push_back(u);
		for(int i : G[u]) {
			--indeg[i];
			if(indeg[i] == 0) que.push(i);
		}
	}
	reverse(ans.begin(), ans.end());
	vector<int> perm(N);
	for(int i = 0; i < N; ++i) {
		perm[ans[i]] = i;
	}
	for(int i = 0; i < N; ++i) {
		if(i) cout << ' ';
		cout << perm[i] + 1;
	}
	cout << '\n';
	return 0;
}