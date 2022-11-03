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

int n, m;
vector<int> a[1505], b[1505], c[1505];
bool lgl[1505];

const int maxn = 1 << 11;
struct Zkwseg {
	int dt[maxn << 1];
	void inline add(int a, int x) {
		dt[a += maxn] = x;
		while (a >>= 1) dt[a] = min(dt[a << 1], dt[a << 1 | 1]);
	}
	int inline get(int a) { return dt[a + maxn]; }
} seg[1505];

int main() {
	scanf("%d%d", &n, &m);
	cont(i, n) {
		a[i].resize(m + 1);
		cont(j, m) scanf("%d", &a[i][j]);
	}
	cont(i, n) {
		b[i].resize(m + 1);
		cont(j, m) scanf("%d", &b[i][j]);
		c[i] = b[i];
	}
	sort(a + 1, a + n + 1); sort(c + 1, c + n + 1);
	cont(i, n) if (a[i] != c[i]) return puts("-1"), 0;
	cont(i, n - 1) cont(j, m) b[i][j] = b[i + 1][j] - b[i][j], seg[j].add(i, b[i][j]);
	vector<int> op; int as = 0;
	cont(i, m) {
		int ch = -1;
		cont(j, m) if (!lgl[j] && seg[j].dt[1] >= 0) {
			ch = j; break;
		}
		if (!~ch) return puts("-1"), 0;
		vector<int> zs;
		cont(j, n - 1) if (seg[ch].get(j)) zs.pub(j), ++as;
		loop(i, SZ(zs)) cont(j, m) seg[j].add(zs[i], 0);
		op.pub(ch);
		lgl[ch] = 1;
		if (as == n - 1) break;
	}
	reverse(all(op));
	printf("%d\n", SZ(op));
	loop(i, SZ(op)) printf("%d ", op[i]);
	return 0;
}