/* by Hyperhydrochloric Acid */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); ++i)
#define cont(i, n)          for(int i = 1; i <= (n); ++i)
#define circ(i, a, b)       for(int i = (a); i <= (b); ++i)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define y0          y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1          y1II11II11III11I1III11II111IIII1II1I1
#define pub         push_back
#define pob         pop_back
#define mak         make_pair
typedef long long   ll;
typedef long double lf;
const int   Inf = 0x3f3f3f3f;
const ll    INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

int nxt[20005][26];
int fa[20005], len[20005];
int nds = 1, lst = 1;
int cnt[2][20005];

void inline append(int c, int m) {
	int p = lst, np = ++nds;
	len[np] = len[p] + 1;
	while(p && !nxt[p][c]) {
		nxt[p][c] = np;
		p = fa[p];
	}
	if(!p) {
		fa[np] = 1;
	} else {
		int q = nxt[p][c];
		if(len[q] == len[p] + 1) {
			fa[np] = q;
		} else {
			int nq = ++nds;
			memcpy(nxt[nq], nxt[q], sizeof(nxt[q]));
			fa[nq] = fa[q]; fa[q] = fa[np] = nq;
			len[nq] = len[p] + 1;
			while(p && nxt[p][c] == q) {
				nxt[p][c] = nq;
				p = fa[p];
			}
		}
	}
	lst = np;
	cnt[m][np] = 1;
}

char s[5005], t[5005];
vector<int> nei[20005];
int ans = Inf;

void dfs(int now) {
	loop(i, SZ(nei[now])) {
		int to = nei[now][i];
		dfs(to);
		cnt[0][now] += cnt[0][to];
		cnt[1][now] += cnt[1][to];
	}
	if(now > 1 && cnt[0][now] == 1 && cnt[1][now] == 1) {
		ans = min(ans, len[fa[now]] + 1);
	}
}

int main() {
	scanf("%s", s);
	scanf("%s", t);
	for(int i = 0; s[i]; ++i) append(s[i] - 'a', 0);
	lst = 1;
	for(int i = 0; t[i]; ++i) append(t[i] - 'a', 1);
	cont(i, nds) nei[fa[i]].pub(i);
	dfs(1);
	printf("%d\n", ans == Inf ? -1 : ans);
	return 0;
}