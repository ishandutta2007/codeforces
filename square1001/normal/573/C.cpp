#include <cstdio>
#include <vector>
using namespace std;
int readint() {
	char c = getchar();
	int ans = 0;
	while('0' <= c && c <= '9') {
		ans = ans * 10 + int(c - '0');
		c = getchar();
	}
	return ans;
}
int dfs1(int pos, int pre, vector<vector<int> > &G, vector<int> &state) {
	int cnt = 0; bool ok = true;
	for(int i : G[pos]) {
		if(i == pre) continue;
		int res = dfs1(i, pos, G, state);
		if(res >= 2) ok = false;
		++cnt;
	}
	if(!ok) return state[pos] = 3;
	return state[pos] = cnt;
}
void dfs2(int pos, int pre, vector<vector<int> > &G, vector<int> &state1, vector<int> &state2) {
	vector<int> child;
	for(int i : G[pos]) {
		if(i == pre) continue;
		child.push_back(state1[i]);
	}
	if(child.size() <= 1 || (child.size() == 2 && (child[0] <= 1 || child[1] <= 1))) {
		state2[pos] = child.size();
	}
	if(child.size() >= 2) return;
	for(int i : G[pos]) {
		if(i == pre) continue;
		dfs2(i, pos, G, state1, state2);
	}
}
int main() {
	int N = readint();
	vector<vector<int> > G(N);
	for(int i = 0; i < N - 1; ++i) {
		int a = readint() - 1;
		int b = readint() - 1;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int root = -1;
	for(int i = 0; i < N; ++i) {
		if(G[i].size() == 1) {
			root = i;
			break;
		}
	}
	if(root == -1) root = 0;
	vector<int> state1(N), state2(N, 3);
	dfs1(root, -1, G, state1);
	dfs2(root, -1, G, state1, state2);
	bool ans = true;
	for(int i = 0; i < N; ++i) {
		if(state1[i] != 3 || state2[i] != 3) continue;
		int deg = 0;
		for(int j : G[i]) {
			if(state1[j] != 3 || state2[j] != 3) continue;
			++deg;
		}
		if(deg >= 3) {
			ans = false;
			break;
		}
	}
	printf(ans ? "Yes\n" : "No\n");
	return 0;
}