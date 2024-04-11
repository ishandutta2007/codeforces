#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define foreach(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

struct UnionFind {
	int fa[55];
	void inline init() { memset(fa, -1, sizeof(fa)); }
	UnionFind() { init(); }
	int inline root(int x) { return fa[x] < 0 ? x : fa[x] = root(fa[x]); }
	bool inline conn(int a, int b) {
		a = root(a);
		b = root(b);
		if (a == b) return 0;
		if (fa[a] < fa[b]) swap(a, b);
		return fa[b] += fa[a], fa[a] = b, 1;
	}
} uf;

const int jt = 1000000007;
int n;
char s[55][55];
vector<int> ls[55];
int rr[55];
int ban[25];
int f[1 << 23], g[1 << 23];

int main() {
	scanf("%d", &n);
	cont(i, n) scanf("%s", s[i] + 1);
	uf.init();
	cont(i, n) cont(j, n) if (s[i][j] == 'A') uf.conn(i, j);
	cont(i, n) cont(j, n) if (s[i][j] == 'X' && uf.root(i) == uf.root(j)) return puts("-1"), 0;
	int $b = 0;
	cont(i, n) if (uf.root(i) == i) rr[i] = ++$b;
	cont(i, n) ls[rr[uf.root(i)]].pub(i);
	sort(ls + 1, ls + $b + 1, [&](const vector<int> &a, const vector<int> &b) { return SZ(a) > SZ(b); });
	cont(i, n) loop(j, SZ(ls[i])) rr[ls[i][j]] = i;
	int res = n - 1;
	while (SZ(ls[$b]) == 1) --$b;
	if (!$b) return printf("%d\n", res), 0;
	cont(i, n) cont(j, n) if (s[i][j] == 'X') {
		int $i = rr[uf.root(i)] - 1, $j = rr[uf.root(j)] - 1;
		if ($i >= $b || $j >= $b) continue;
		ban[$i] |= (1 << $j);
		ban[$j] |= (1 << $i);
	}
	loop(i, 1 << $b) {
		bool can = 1;
		loop(j, $b) if (((i >> j) & 1) && ban[j] & i) {
			can = 0;
			break;
		}
		if (can) f[i] = 1;
	}
	loop(i, $b) loop(j, 1 << $b) if ((j >> i) & 1) f[j] += f[j ^ (1 << i)];
	loop(i, 1 << $b) g[i] = 1;
	loop(i, $b + 1) {
		ll al = 0;
		loop(j, 1 << $b) {
			if (($b - __builtin_popcount(j)) & 1)
				al -= g[j];
			else
				al += g[j];
		}
		if (al % jt) {
			res += i;
			break;
		}
		loop(j, 1 << $b) g[j] = 1ll * f[j] * g[j] % jt;
	}
	printf("%d\n", res);
	return 0;
}