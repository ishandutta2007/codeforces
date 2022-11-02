#include <bits/stdc++.h>
using namespace std;
#define N 300300

int n, m, cnt, f[N], mnr[N], mlen[N], len[N];
bool vis[N];
vector <int> v[N];
string word[N], A, B;
map <string, int> mp;

vector <int> V[N], RV[N];
int ord[N], FTIME;
int col[N], C;

void DFS(int u) {
	vis[u] = 1;
	for (int i = 0; i < V[u].size(); i ++) {
		int v = V[u][i];
		if (!vis[v]) DFS(v);
	}
	ord[FTIME --] = u;
}

void DFS_(int u) {
	vis[u] = 1;
	col[u] = C;
	for (int i = 0; i < RV[u].size(); i ++) {
		int v = RV[u][i];
		if (!vis[v]) DFS_(v);
	}
}


void dfs(int x) {
	vis[x] = 1;
	for (int i = 0; i < v[x].size(); i ++) {
		int y = v[x][i];
		if (!vis[y]) dfs(y);
		if (mnr[x] > mnr[y]) mnr[x] = mnr[y], mlen[x] = mlen[y];
		else if (mnr[x] == mnr[y]) mlen[x] = min(mlen[x], mlen[y]);
	}
}

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		cin >> word[i];
		int r = 0;
		for (int j = 0; j < word[i].size(); j ++) {
			if (word[i][j] >= 'A' && word[i][j] <= 'Z') word[i][j] = word[i][j] - 'A' + 'a';
			if (word[i][j] == 'r') r ++;
		}
		if (!mp.count(word[i])) mp[word[i]] = ++cnt, f[cnt] = r, len[cnt] = word[i].size();
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i ++) {
		cin >> A >> B;
		int r = 0;
		for (int j = 0; j < A.size(); j ++) {
			if (A[j] >= 'A' && A[j] <= 'Z') A[j] = A[j] - 'A' + 'a';
			if (A[j] == 'r') r ++;
		}
		if (!mp.count(A)) mp[A] = ++cnt, f[cnt] = r, len[cnt] = A.size();
		r = 0;
		for (int j = 0; j < B.size(); j ++) {
			if (B[j] >= 'A' && B[j] <= 'Z') B[j] = B[j] - 'A' + 'a';
			if (B[j] == 'r') r ++;
		}
		if (!mp.count(B)) mp[B] = ++cnt, f[cnt] = r, len[cnt] = B.size();
		int a = mp[A], b = mp[B];
		V[a].push_back(b), RV[b].push_back(a);
	}

	FTIME = cnt;
	for (int i = 1; i <= cnt; i ++) if (!vis[i]) DFS(i);

	memset(vis, 0, sizeof vis);
	C = 0;
	for (int i = 1; i <= cnt; i ++) if (!vis[ord[i]]) {
		C ++;
		DFS_(ord[i]);
	}

	for (int i = 1; i <= C; i ++) mnr[i] = mlen[i] = 1 << 30;
	for (int i = 1; i <= cnt; i ++) {
		if (mnr[col[i]] > f[i]) mnr[col[i]] = f[i], mlen[col[i]] = len[i];
		else if (mnr[col[i]] == f[i]) mlen[col[i]] = min(mlen[col[i]], len[i]);
	}

	for (int i = 1; i <= cnt; i ++) {
		for (int j = 0; j < V[i].size(); j ++) {
			if (col[i] != col[V[i][j]]) v[col[i]].push_back(col[V[i][j]]);
		}
	}

	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= cnt; i ++) if (!vis[i]) dfs(i);

	int R = 0;
	long long Len = 0;
	for (int i = 1; i <= n; i ++) {
		int x = mp[word[i]];
		R += mnr[col[x]], Len += mlen[col[x]];
	}
	cout << R << ' ' << Len << endl;
	return 0;
}