#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 2E5 + 10, MAXM = 4E5 + 10;

int n, m;
vector<PII> E[MAXN];
PII e[MAXM];
int fa[MAXN];

int a[2], b[2];
int c[2][MAXN];
bool connFlag;

int find(int x){
	return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

void solve(int c[], int u, int other){
	for (int v, i = 0; i < E[u].size(); ++i){
		if ((v = E[u][i].st) == other){
			connFlag = true;
			continue;
		}

		int w = find(E[u][i].st);
		if (c[w] == 0)
			c[w] = v;
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		fa[i] = i;
	for (int u, v, i = 0; i < m; ++i){
		scanf("%d%d", &u, &v);
		e[i] = PII(u, v);
		E[u].push_back(PII(v, i));
		E[v].push_back(PII(u, i));
	}
	scanf("%d%d%d%d", &a[0], &a[1], &b[0], &b[1]);

	sort(e, e + m);
	vector<PII> ans;
	int tot = n - 2;
	for (int i = 0; i < m; ++i){
		if (e[i].st == a[0] || e[i].st == a[1] || e[i].nd == a[0] || e[i].nd == a[1])
			continue;
		int u = find(e[i].st), v = find(e[i].nd);
		if (u != v){
			fa[u] = v, --tot;
			ans.push_back(e[i]);
//			printf("--- %d %d %d %d\n", e[i].st, e[i].nd);
		}
	}

	solve(c[0], a[0], a[1]);
	solve(c[1], a[1], a[0]);
	vector<PII> lst;
	for (int i = 1; i <= n; ++i){
		if (c[0][i] && !c[1][i])
			ans.push_back(PII(a[0], c[0][i])), --b[0];
		if (c[1][i] && !c[0][i])
			ans.push_back(PII(a[1], c[1][i])), --b[1];
		if (c[0][i] && c[1][i])
			lst.push_back(PII(c[0][i], c[1][i]));
	}
//	printf("%d %d %d\n", ans.size(), lst.size(), connFlag);
	if (b[0] <= 0 || b[1] <= 0){
//		nothing
	}
	else if (lst.size() == 0){
		if (connFlag)
			ans.push_back(PII(a[0], a[1]));
		else{
			// nothing
		}
	}
	else{
		--b[0], --b[1];
		ans.push_back(PII(a[0], lst[0].st));
		ans.push_back(PII(a[1], lst[0].nd));
		for (int i = 1; i < lst.size(); ++i)
			if (b[0])
				ans.push_back(PII(a[0], lst[i].st)), --b[0];
			else if (b[1])
				ans.push_back(PII(a[1], lst[i].nd)), --b[1];
	}
	if (ans.size() < n - 1)
		puts("No");
	else{
		puts("Yes");
		for (int i = 0; i < ans.size(); ++i)
			printf("%d %d\n", ans[i].st, ans[i].nd);
	}

	return 0;
}