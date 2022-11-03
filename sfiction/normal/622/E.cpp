#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 5E5 + 10;

int n;
vector<int> E[MAXN];
vector<int> lst;

void DFS(int u, int pre, int depth){
	if (E[u].size() == 1)
		lst.push_back(depth);
	for (int i = 0; i < E[u].size(); ++i)
		if (E[u][i] != pre)
			DFS(E[u][i], u, depth + 1);
}

int main(){
	scanf("%d", &n);
	for (int u, v, i = 1; i < n; ++i){
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	int ans = 0;
	for (int i = 0; i < E[1].size(); ++i){
		lst.clear();
		DFS(E[1][i], 1, 1);
		sort(lst.begin(), lst.end());
		for (int j = 1; j < lst.size(); ++j)
			if (lst[j] <= lst[j - 1])
				lst[j] = lst[j - 1] + 1;
		ans = max(ans, lst.back());
	}
	printf("%d\n", ans);
	return 0;
}