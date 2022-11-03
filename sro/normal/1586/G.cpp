#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

const int jt = 1000000007, maxn = 400005;
void inline add(int &a, int b) { a += b - jt; a += (a >> 31) & jt; }
void inline sub(int &a, int b) { a -= b; a += (a >> 31) & jt; }
void inline mul(int &a, int b) { a = 1ll * a * b % jt; }
int inline Add(int a, int b) { return a + b >= jt ? a + b - jt : a + b; }
int inline Sub(int a, int b) { return a - b < 0 ? a - b + jt : a - b; }
int inline Mul(int a, int b) { return 1ll * a * b % jt; }

struct Fenwick {
	int dt[maxn];
	void inline add(int a, int x) {
		while (a < maxn) ::add(dt[a], x), a += a & -a;
	}
	int inline sum(int a) {
		int res = 0;
		while (a) ::add(res, dt[a]), a -= a & -a;
		return res;
	}
} bit;

int N;
int a[maxn], b[maxn];
int mxl[maxn];

int main() {
	scanf("%d", &N);
	vector<pair<int, int> > al;
	for (int i = 1; i <= N; ++i) scanf("%d%d", a + i, b + i), al.emplace_back(a[i], b[i]);
	sort(al.begin(), al.end());
	int T; scanf("%d", &T);
	for (int i = 1; i <= T; ++i) {
		int id; scanf("%d", &id);
		mxl[b[id]] = a[id];
	}
	for (int i = N << 1; i; --i) mxl[i] = max(mxl[i], mxl[i + 1]);
	int ans = 0;
	for (auto &it : al) {
		int a, b; tie(a, b) = it;
		int ts = mxl[b] >= a;
		add(ts, Sub(bit.sum(maxn - 1), bit.sum(b)));
		add(ans, ts);
		bit.add(b, ts);
	}
	printf("%d\n", ans);
	return 0;
}