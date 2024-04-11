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

const int Bl = 365;
int n, q, bls;
int a[100005];
int p[100005], tag[100005];

int inline gfa(int i) { return max(1, a[i] - tag[i / Bl]); }

void inline update(int b) {
	int l = max(1, b * Bl), r = min(n, (b + 1) * Bl - 1);
	circ(i, l, r) {
		int to = max(1, a[i] - tag[b]);
		p[i] = (to == 1 || to < l ? to : p[to]);
	}
}

int main() {
	scanf("%d%d", &n, &q); bls = n / Bl + 1;
	a[1] = 1;
	circ(i, 2, n) scanf("%d", a + i);
	loop(i, bls) update(i);
	cont(i, q) {
		int mode; scanf("%d", &mode);
		if (mode == 1) {
			int l, r, x; scanf("%d%d%d", &l, &r, &x);
			int L = l / Bl, R = r / Bl;
			if (L == R) {
				circ(i, l, r) a[i] = max(1, a[i] - x);
				update(L); continue;
			}
			circ(i, l, (L + 1) * Bl - 1) a[i] = max(1, a[i] - x);
			circ(i, R * Bl, r) a[i] = max(1, a[i] - x);
			update(L); update(R);
			circ(i, L + 1, R - 1) {
				tag[i] += x;
				if (tag[i] <= Bl + x) update(i);
				tag[i] = min(tag[i], Inf); // 
			}
		} else {
			int l, r; scanf("%d%d", &l, &r);
			while (1) {
				int L = l / Bl, R = r / Bl;
				if (L > R) swap(L, R), swap(l, r);
				if (L < R) { r = min(gfa(r), p[r]); continue; }
				int pl = min(gfa(l), p[l]), pr = min(gfa(r), p[r]);
				if (pl != pr) { l = pl; r = pr; continue; }
				while (l != r) {
					if (l > r) l = gfa(l);
					else r = gfa(r);
				}
				printf("%d\n", l); break;
			}
		}
	}
	return 0;
}