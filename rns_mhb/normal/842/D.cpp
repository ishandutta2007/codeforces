#include <bits/stdc++.h>
using namespace std;
#define N 300010
#define K 19
#define inf 1000000000
#define ep 1e-9
#define mp make_pair
#define pb push_back
template<class T> void chkmax(T &a, T b) {if (a < b) a = b;}
template<class T> void chkmin(T &a, T b) {if (a > b) a = b;}
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, x;
int a[N];

int v[N<<2][2];
bool vis[N<<2], rev[K<<1], pft[N<<2];

void build() {
	vector<int> tmp;
	int tot = 0;
	for (int i = 1, m; i <= n; i ++) {
		tmp.clear();
		m = a[i];
		for (int i = 1; i <= K; i ++) {
			tmp.pb(m&1);
			m >>= 1;
		}
		int node = 0;
		for (int i = K - 1; i >= 0; i --) {
			if (v[node][tmp[i]] == 0) v[node][tmp[i]] = ++tot;
			node = v[node][tmp[i]];
		}
		vis[node] = 1;
	}
}

void dfs(int nd) {
	int cnt = 0;
	for (int i = 0; i < 2; i ++) {
		if (v[nd][i]) {
			cnt ++;
			dfs(v[nd][i]);
		}
	}
	if (cnt == 0) pft[nd] = 1;
	else if (cnt == 2 && pft[v[nd][0]] && pft[v[nd][1]]) pft[nd] = 1;
}

int an, k;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%d", a + i);
	build();
	dfs(0);
	while (m --) {
		scanf("%d", &x);
		for (int i = K; i >= 1; i --) {
			rev[i] ^= (x&1);
			x >>= 1;
		}
		an = 0;
		for (int i = 1, nd = 0; i <= K; i ++) {
			if (!v[nd][rev[i]]) {
				an <<= (K + 1 - i);
				break;
			}
			else if (pft[v[nd][rev[i]]]) {
				an = 2 * an + 1;
				if (!v[nd][1-rev[i]]) {an <<= (K - i); break;}
				else nd = v[nd][1-rev[i]];
			}
			else {
				an = 2 * an;
				nd = v[nd][rev[i]];
			}
		}
		cout<<an<<endl;
	}
    return 0;
}