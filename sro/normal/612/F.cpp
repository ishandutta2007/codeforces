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

// #define printf [&](...){}

int n, s;
int a[2005], nxt[2005];
int f1[2005], f2[2005];

int inline dist(int i, int j) {
	if(i > j) swap(i, j);
	return min(j - i, i + n - j);
}

int inline ndist(int i, int j) {
	return (j - i + n) % n;
}

int dfs2(int);

int inline dfs1(int now) {
	int &ans = f1[now];
	if(~ans) return ans;
	ans = Inf;
	range(fx, -1, 1, 2) {
		int to = -1;
		cont(i, n - 1) {
			int nxt = (now + fx * i + n - 1) % n + 1;
			if(a[nxt] == a[now]) {
				to = nxt;
				break;
			}
		}
		if(to == -1) {
			ans = min(ans, dfs2(now));
		} else {
			ans = min(ans, dfs2(to) + (~fx ? ndist(to, now) : ndist(now, to)));
		}
	}
	return ans;
}

int inline dfs2(int now) {
	int &ans = f2[now];
	if(~ans) return ans;
	if(nxt[now] == Inf) return ans = 0;
	ans = Inf;
	cont(i, n) if(a[i] == nxt[now]) {
		ans = min(ans, dfs1(i) + dist(now, i));
	}
	return ans;
}

void sfd2(int);

void inline sfd1(int now) {
	int ans = f1[now];
	range(fx, -1, 1, 2) {
		int to = -1;
		cont(i, n - 1) {
			int nxt = (now + fx * i + n - 1) % n + 1;
			if(a[nxt] == a[now]) {
				to = nxt;
				break;
			}
		}
		if(to == -1) {
			if(dfs2(now) == ans) {
				return sfd2(now);
			}
		} else {
			if(dfs2(to) + (~fx ? ndist(to, now) : ndist(now, to)) == ans) {
				int bs = 0;
				cont(i, n - 1) {
					int nxt = (now - fx * i + n - 1) % n + 1;
					++bs;
					if(a[nxt] == a[now]) {
						printf("%c%d\n", "-+"[!~fx], bs);
						bs = 0;
					}
				}
				return sfd2(to);
			}
		}
	}
}

void inline sfd2(int now) {
	int ans = f2[now];
	cont(i, n) if(a[i] == nxt[now]) {
		if(ans == dfs1(i) + dist(now, i)) {
			int ds = ndist(now, i);
			if(ds < n - ds) printf("+%d\n", ds);
			else printf("-%d\n", n - ds);
			sfd1(i);
			break;
		}
	}
}

int main() {
	scanf("%d%d", &n, &s);
	cont(i, n) scanf("%d", a + i);
	cont(i, n) {
		int fu = Inf;
		cont(j, n) if(a[j] > a[i]) fu = min(fu, a[j]);
		nxt[i] = fu;
	}
	memset(f1, -1, sizeof(f1));
	memset(f2, -1, sizeof(f2));
	int mn = Inf;
	cont(i, n) mn = min(mn, a[i]);
	int bg = -1, res = Inf;
	cont(i, n) {
		if(a[i] != mn) continue;
		res = min(res, dfs1(i) + dist(s, i));
	}
	printf("%d\n", res);
	cont(i, n) {
		if(dfs1(i) + dist(s, i) == res) {
			int ds = ndist(s, i);
			if(ds < n - ds) printf("+%d\n", ds);
			else printf("-%d\n", n - ds);
			sfd1(i);
			break;
		}
	}
	return 0;
}