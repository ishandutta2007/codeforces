#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long LL;
typedef pair<int, int> pii;
const int MN = 1000005;
const int M = 998244353;
int a[MN][2], pos[MN][2];
vector<int> V, S, V0, V1, rlt;
bool vis[MN];
int cnt[2], nt[MN], nxt[MN];
int n;

void find(int st) {
	V.clear(); S.clear();
	cnt[0] = cnt[1] = 0;
	for (int u = st, id = 0; !vis[u]; u = pos[n - a[u][id]][id], id = 1 - id) {
		if (id == 0 && a[u][id] > 0) cnt[1]++, S.push_back(1);
		else if (id == 1 && a[u][id] < 0) cnt[1]++, S.push_back(1);
		else cnt[0]++, S.push_back(0);
		V.push_back(u);
		vis[u] = 1;
	}
}

pii calc(pii x1, pii x2, pii x3, int d) {
	int fi, se;
	if (d == 1) {
		fi = x1.first;
		nxt[x1.second] = x2.first;
		nxt[x2.second] = x3.first;
		se = x3.second;
	}
	else {
		fi = x3.first;
		nxt[x3.second] = x2.first;
		nxt[x2.second] = x1.first;
		se = x1.second;
	}
	return pii(fi, se);
}

pii dfs(int st, int en) {
	pii x1 = pii(V[st], V[st]), x2, x3;
	for (int i = st; i <= en; i++) {
		x2 = dfs(i + 1, nt[i] - 1);
		x3 = pii(V[nt[i] + 1], V[nt[i] + 1]);
		x1 = calc(x1, x2, x3, S[i] ^ (i & 1));
		i = nt[i];
	}
	return x1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= 2 * n; i++) {
		cin >> a[i][0] >> a[i][1];
		pos[a[i][0] + n][0] = i;
		pos[a[i][1] + n][1] = i;
	}
	bool flg = 0;
	for (int i = 1; i <= 2 * n; i++) if (!vis[i]) {
		if (a[i][0] < 0 || a[i][1] < 0) continue;
		find(i);
		if (cnt[0] == cnt[1] + 2) {
			int st = -1;
			for (int j = 0; j < V.size(); j++) {
				vis[V[j]] = 0;
				if (j & 1) {
					if (a[V[j]][0] > 0 && a[V[j]][1] > 0) {
						st = V[j];
					}
				}
			}
			if (st == -1) {
				flg = 1;
				break;
			}
			find(st);
		}
		if (cnt[1] != cnt[0] + 2) flg = 1;
		if (flg) break;
		V0.clear(); V1.clear();
		for (int i = 1; i < S.size() - 1; i++) {
			if (S[i] == 0) {
				if (V1.empty()) V0.push_back(i);
				else {
					nt[V1.back()] = i;
					V1.pop_back();
				}
			}
			else {
				if (V0.empty()) V1.push_back(i);
				else {
					nt[V0.back()] = i;
					V0.pop_back();
				}
			}
		}
		pii p = dfs(1, S.size() - 2);
		nxt[V[0]] = p.first;
		nxt[p.second] = -1;
		for (int u = V[0]; u != -1; u = nxt[u]) rlt.push_back(u); 
	}
	for (int i = 1; i <= 2 * n; i++) if (!vis[i]) flg = 1;
	if (flg) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for (int i : rlt) cout << a[i][0] << ' ' << a[i][1] << endl;

	return 0;
}