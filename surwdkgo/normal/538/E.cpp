#include <stdio.h>
#include <vector>
#include <map>
using namespace std;
int n;
vector<int> edg[1000010];
typedef pair<int, int> P;

P dfs(int v, int p, int g) {
	if (edg[v].size() == 0) {
		return P(1, 1);
	}
	P ret = P(0, 0);
	int ans = p == g ? n+1 : 0;

	for (int i=0; i<edg[v].size(); i++) {
		P c = dfs(edg[v][i], 1-p, g);
		ret.second += c.second;
		if (p == 0 && g == 0) {
			ans = min(ans, c.first);
		} else if (p == 1 && g == 1) {
			ans = min(ans, c.second - c.first);
		} else {
			ans += c.first-1;
		}
	}
	if (p == 0 && g==0) ret.first = ans;
	else if (p == 1 && g==1) ret.first = ret.second - ans;
	else if (p == 0 && g == 1) ret.first = ans + 1;
	else ret.first = ans + edg[v].size();
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i=0; i<n-1; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		edg[u].push_back(v);
	}
	printf("%d %d\n", dfs(1, 1, 1).first, dfs(1, 1, 0).first);
	return 0;
}