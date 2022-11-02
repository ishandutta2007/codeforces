#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long

char ss[N];

int nxt[N][26]; bool vis[N];
int rt, tot, n;

void insert(char *s) {
	int len = strlen(s);
	int nd = rt;
	for (int i = 0; i < len; i ++) {
		if (!nxt[nd][s[i] - 'a']) nxt[nd][s[i] - 'a'] = ++ tot;
		nd = nxt[nd][s[i] - 'a'];
	}
	vis[nd] = 1;
}

multiset <int> s[N];

void dfs(int k, int dep) {
    int hs = k, d = 0;
    for (int i = 0; i < 26; i ++) if (nxt[k][i]) {
		int y = nxt[k][i];
        dfs(y, dep + 1);
        if (s[y].size() > d) {
            hs = y;
            d = s[y].size();
        }
    }
    swap(s[k], s[hs]);
    for (int i = 0; i < 26; i ++) {
		int y = nxt[k][i];
		if (!y || y == hs) continue;
        for (auto x : s[y]) s[k].insert(x);
    }
    if (vis[k]) s[k].insert(dep);
    if (!vis[k] && dep) {
        s[k].erase(prev(s[k].end()));
        s[k].insert(dep);
    }
    return;
}

int main() {
    for (scanf("%d", &n); n --; ) {
        scanf("%s", ss);
        insert(ss);
    }
    dfs(0, 0);
    ll sum = 0;
    for (auto x : s[0]) sum += x;
    printf("%I64d\n", sum);
}