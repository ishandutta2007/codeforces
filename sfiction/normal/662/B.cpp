#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 1E5 + 10;

int n, m;
vector<PII> E[MAXN];

char sym;
int color[MAXN];
vector<int> a[2];

bool DFS(int u){
	a[color[u]].push_back(u);
	bool flag;
	for (int v, i = 0; i < E[u].size(); ++i){
		flag = color[u] ^ E[u][i].nd != sym;
		v = E[u][i].st;
		if (color[v = E[u][i].st] == -1){
			color[v] = flag;
			DFS(v);
		}
		else if (color[v] != flag)
			return false;
	}
	return true;
}

int main(){
	scanf("%d%d", &n, &m);
	char s[5];
	for (int u, v, i = 0; i < m; ++i){
		scanf("%d%d%s", &u, &v, s);
		E[u].push_back(PII(v, s[0]));
		E[v].push_back(PII(u, s[0]));
	}

	vector<int> ans[2];
	for (int ri = 0; ri < 2; ++ri){
		sym = ri ? 'R' : 'B';
		memset(color, -1, sizeof(color));
		for (int i = 1; i <= n; ++i)
			if (color[i] == -1){
				color[i] = 0;
				a[0].clear(), a[1].clear();
				if (!DFS(i)){
					ans[ri].clear();
					ans[ri].push_back(0);
					break;
				}
				vector<int> &b = a[a[1].size() < a[0].size()];
				for (int j = 0; j < b.size(); ++j)
					ans[ri].push_back(b[j]);
			}
	}
	int t = -1;
	if (ans[0].size() == 1 && ans[0][0] == 0)
		t = 1;
	else if (ans[1].size() == 1 && ans[1][0] == 0)
		t = 0;
	else
		t = ans[1].size() < ans[0].size();
	if (ans[t].size() == 1 && ans[t][0] == 0)
		puts("-1");
	else{
		printf("%d\n", (int)ans[t].size());
		for (int i = 0; i < ans[t].size(); ++i)
			printf("%d%c", ans[t][i], "\n "[i + 1 < ans[t].size()]);
	}
	return 0;
}