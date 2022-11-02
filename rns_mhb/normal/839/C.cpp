#include <bits/stdc++.h>
using namespace std;
#define N 200010
#define inf 1000000000
#define ep 1e-9
#define mp make_pair
#define pb push_back
#define ll long long
template<class T> void chkmax(T &a, T b) {if (a < b) a = b;}
template<class T> void chkmin(T &a, T b) {if (a > b) a = b;}
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
vector<int> adj[N];

double dfs(int u, int pa = 0) {
	double tmp = 0;
	int cnt = 0;
	for (int i = 0, v; i < adj[u].size(); i ++) {
		v = adj[u][i];
		if (v == pa) continue;
		cnt ++;
		tmp += dfs(v, u);
	}
	if (!cnt) return 0;
	tmp /= cnt;
	tmp += 1;
	return tmp;
}

int main() {
	scanf("%d", &n);
	int m = n - 1;
	int u, v;
	while (m --) {
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	printf("%.12lf", dfs(1));
    return 0;
}