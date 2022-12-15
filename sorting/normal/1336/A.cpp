#include <bits/stdc++.h>

using namespace std;

const int kN = 2e5 + 7;

int depth[kN], subtree_size[kN], permutation[kN], position[kN], parent[kN];
int cnt[kN];
int n, k;
vector<int> adjacent[kN];
priority_queue<pair<long long, int>> q;

long long get_answer(){
	for(int i = 1; i <= n; ++i)
		if(subtree_size[i] == 1)
			q.push({depth[i] - subtree_size[i] + 1, i});

	for(int i = 1; i <= n; ++i){
		if(i == 1)
			cnt[i] = adjacent[i].size();
		else
			cnt[i] = adjacent[i].size() - 1;
	}

	long long answer = 0;
	for(int i = 1; i <= k; ++i){
		auto p = q.top();
		q.pop();

		int u = p.second;
		answer += p.first;

		int par = parent[u];
		if(par == -1)
			continue;

		--cnt[par];
		if(!cnt[par])
			q.push({depth[par] - subtree_size[par] + 1, par});
	}

	return answer;
}

void build_depth(int u, int par = -1){
	depth[u] = (par == -1) ? 0 : depth[par] + 1;
	subtree_size[u] = 1;
	parent[u] = par;
	for(int to: adjacent[u]){
		if(to == par)
			continue;
		build_depth(to, u);
		subtree_size[u] += subtree_size[to];
	}
}

void read(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;

		adjacent[u].push_back(v);
		adjacent[v].push_back(u);
	}
}

int main(){
	read();
	build_depth(1);
	cout << get_answer() << "\n";
}