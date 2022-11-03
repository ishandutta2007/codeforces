#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define parse(it, x) for (auto &it : (x))
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

const int maxn = 200005;
int n;
int a[maxn];
int nds = 1, son[maxn << 5][2];
vector<int> hv[maxn << 5];
int cnt[maxn << 5];

void inline add(int a, int x) {
	int now = 1;
	range(i, 29, 0, -1) {
		int val = (a >> i) & 1;
		if (!son[now][val]) son[now][val] = ++nds;
		now = son[now][val]; ++cnt[now];
	}
	hv[now].pub(x);
}

void inline addv(int a, int x) {
	int now = 1;
	range(i, 29, 0, -1) {
		int val = (a >> i) & 1;
		if (!son[now][val]) son[now][val] = ++nds;
		now = son[now][val]; cnt[now] += x;
	}
}

pair<int, int> inline get(int a) {
	int now = 1, res = 0;
	range(i, 29, 0, -1) {
		int val = (a >> i) & 1;
		if (cnt[son[now][val]]) now = son[now][val];
		else now = son[now][val ^ 1], res += 1 << i;
	}
	return mak(res, now);
}

struct UnionFind {
	int fa[maxn];
	void inline init() { memset(fa, -1, sizeof(fa)); }
	int inline root(int x) { return fa[x] < 0 ? x : (fa[x] = root(fa[x])); }
	bool inline conn(int a, int b) {
		a = root(a); b = root(b);
		if (a == b) return 0;
		if (fa[a] < fa[b]) swap(a, b);
		return fa[b] += fa[a], fa[a] = b, 1;
	}
} uf;

vector<int> has[maxn];
bool lgl[maxn];

int main() {
	scanf("%d", &n);
	cont(i, n) scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	cont(i, n) add(a[i], i);
	ll ans = 0;
	uf.init();
	while (1) {
		cont(i, n) has[i].clear();
		cont(i, n) has[uf.root(i)].pub(i);
		cont(i, n) if (SZ(has[i])) {
			if (SZ(has[i]) == n) goto fin;
			parse(it, has[i]) addv(a[it], -1), lgl[it] = 1;
			pair<int, int> res = mak(Inf, Inf);
			parse(it, has[i]) res = min(res, get(a[it]));
			int sel = -1;
			parse(it, hv[res.second]) if (!lgl[it]) {
				sel = it; break;
			}
			if (uf.conn(i, sel)) ans += res.first;
			parse(it, has[i]) addv(a[it], 1), lgl[it] = 0;
		}
	}
fin:
	printf("%lld\n", ans);
	return 0;
}