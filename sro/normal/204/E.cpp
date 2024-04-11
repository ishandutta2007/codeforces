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

const int qwq = 150010;
int n, k;
char tmp[qwq];
int tr[qwq][26], nds = 1;
int to[qwq << 1][26], fa[qwq << 1], len[qwq << 1], fid[qwq << 1];
int cnt[qwq << 1];
vector<int> ts[qwq];
int qzh[qwq << 1];
int lgl[qwq << 1];
char buf[qwq * 10], tt[20];
int bufid;
int ord[qwq << 1], cns[qwq];

void inline add(int p, int c) {
	int np = tr[p][c]; len[np] = len[p] + 1;
	while(p && !to[p][c]) {
		to[p][c] = np;
		p = fa[p];
	}
	if(!p) {
		fa[np] = 1;
	} else {
		int q = to[p][c];
		if(len[q] == len[p] + 1) {
			fa[np] = q;
		} else {
			int nq = ++nds;
			memcpy(to[nq], to[q], sizeof(to[q]));
			fa[nq] = fa[q]; fa[q] = fa[np] = nq;
			len[nq] = len[p] + 1;
			while(p && to[p][c] == q) {
				to[p][c] = nq;
				p = fa[p];
			}
		}
	}
}

void dfs(int now) {
	loop(c, 26) {
		int to = tr[now][c];
		if(!to) continue;
		add(now, c);
		dfs(to);
	}
}

// void dfu(int now) {
// 	if(cnt[now] >= k) mxl[now] = len[now];
// 	const int ns = SZ(nei[now]);
// 	loop(i, ns) {
// 		int to = nei[now][i];
// 		mxl[to] = mxl[now];
// 		dfu(to);
// 	}
// }

int main() {
	scanf("%d%d", &n, &k);
	fread(buf, 1, qwq << 1, stdin);
	cont(i, n) {
		int len = 0;
		while(buf[bufid] < 'a' || buf[bufid] > 'z') ++bufid;
		while(buf[bufid] >= 'a' && buf[bufid] <= 'z') {
			tmp[len++] = buf[bufid++];
		}
		int now = 1;
		loop(j, len) {
			if(!tr[now][tmp[j] - 'a']) {
				tr[now][tmp[j] - 'a'] = ++nds;
			}
			now = tr[now][tmp[j] - 'a'];
			ts[i].pub(now);
		}
	}
	// cerr<<clock()<<endl;
	dfs(1);
	int mxn = 0;
	cont(i, nds) ++cns[len[i]], mxn = max(mxn, len[i]);
	cont(i, mxn) cns[i] += cns[i - 1];
	cont(i, nds) ord[cns[len[i]]--] = i;
	// cerr<<clock()<<endl;
	// cont(i, nds) nei[fa[i]].pub(i);
	// cerr<<clock()<<endl;
	cont(i, n) {
		loop(j, SZ(ts[i])) {
			int now = ts[i][j];
			while(now && lgl[now] != i && cnt[now] < k) {
				lgl[now] = i;
				++cnt[now];
				now = fa[now];
			}
		}
	}
	cont(i, nds) qzh[i] = (cnt[i] >= k) ? len[i] - len[fa[i]] : 0;
	cont(i, nds) qzh[ord[i]] += qzh[fa[ord[i]]];
	// cerr<<clock()<<endl;
	// dfu(1);
	bufid = 0;
	cont(i, n) {
		ll ans = 0;
		loop(j, SZ(ts[i])) ans += qzh[ts[i][j]];
		if(!ans) buf[bufid++] = '0';
		char tid = 0;
		while(ans) tt[tid++] = ans % 10 + '0', ans /= 10;
		range(i, tid - 1, 0, -1) buf[bufid++] = tt[i];
		buf[bufid++] = ' ';
	}
	fwrite(buf, 1, bufid, stdout);
	return 0;
}