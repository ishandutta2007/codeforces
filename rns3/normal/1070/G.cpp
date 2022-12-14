#include <bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define ep 1e-9
#define mp make_pair
#define pb push_back
#define ll long long
#pragma comment(linker, "/STACK:1024000000,1024000000")
template<class T> void chkmax(T &a, T b) {if (a < b) a = b;}
template<class T> void chkmin(T &a, T b) {if (a > b) a = b;}
typedef pair<int, int> pii;
const double pi = 3.1415926535897932384626433832795028841971l;

#define N 110

int n, m, s[N], h[N], p[N], a[N], hh[N];

int l[N], r[N], nxt[N], prv[N];
int gl[N], gr[N];
bool vis[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i ++) scanf("%d%d", &s[i], &h[i]), p[s[i]] = i;
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	sort(s + 1, s + m + 1);
	for (int i = 1; i <= m; i ++) hh[i] = h[p[s[i]]];
	swap(h, hh);
	for (int ral = 0; ral <= n; ral ++) {
		for (int i = 1; i <= m; i ++) {
			int j, hp;
			for (j = s[i], hp = h[i]; j <= ral; j ++) {
				hp += a[j];
				if (hp < 0) break;
			}
			r[i] = j - 1;
			for (j = s[i], hp = h[i]; j > ral; j --) {
				hp += a[j];
				if (hp < 0) break;
			}
			l[i] = j + 1;
		}
		for (int i = 0; i <= n + 1; i ++) prv[i] = inf, nxt[i] = 0;
		for (int i = 1; i <= m; i ++) {
			for (int j = s[i]; j <= r[i]; j ++) chkmin(prv[j], s[i]);
			for (int j = l[i]; j <= s[i]; j ++) chkmax(nxt[j], s[i]);
		}
		for (int i = 0; i <= s[1]; i ++) gl[i] = 1;
		for (int i = s[1] + 1; i <= ral; i ++) {
			if (prv[i] == inf) gl[i] = 0;
			else gl[i] = gl[prv[i]-1];
		}
		for (int i = s[m]; i <= n + 1; i ++) gr[i] = 1;
		for (int i = s[m] - 1; i > ral; i --) {
			if (nxt[i] == 0) gr[i] = 0;
			else gr[i] = gr[nxt[i]+1];
		}
		vector<int> ans;
		ans.clear();
		memset(vis, 0, sizeof vis);
		if (gl[ral] && gr[ral+1]) {
			int now = ral;
			while (1) {
				if (prv[now] == inf) break;
				ans.pb(p[prv[now]]);
				vis[p[prv[now]]] = 1;
				now = prv[now] - 1;
			}
			now = ral + 1;
			while (1) {
				if (nxt[now] == 0) break;
				ans.push_back(p[nxt[now]]);
				vis[p[nxt[now]]] = 1;
				now = nxt[now] + 1;
			}
			for (int i = 1; i <= m; i ++) if (!vis[i]) ans.push_back(i);
			if (ral < s[1]) printf("%d\n", ral + 1);
			else printf("%d\n", ral);
			for (auto x: ans) printf("%d ", x);
			puts("");
			return 0;
		}
	}
	puts("-1");
    return 0;
}