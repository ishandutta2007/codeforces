#include <bits/stdc++.h>

using namespace std;
#define maxn 100010

int n;
int subsize[maxn];
vector<int> ch[maxn];
vector<int> nums;

void dfs(int u) {
	subsize[u] = 0;

	if (ch[u].size() == 0) {
		subsize[u]++;
	}
	for (int v : ch[u]) {
		dfs(v);
		subsize[u] += subsize[v];
	}
	nums.push_back(subsize[u]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int p;
	for (int i = 2; i <= n; i++) {
		cin >> p;
		ch[p].push_back(i);
	}

	dfs(1);
	sort(nums.begin(), nums.end());

	for (int val : nums) {
		cout << val << " ";
	}
	cout << endl;
}