#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for(int i = 0; i < (a); ++i)
#define cont(i, a) for(int i = 1; i <= (a); ++i)
#define circ(i, a, b) for(int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for(int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define foreach(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define pub push_back
#define pob pop_back
#define mak make_pair
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

const int jt = 1000000007;

void inline add(int &a, int b) {
	a += b; if(a >= jt) a -= jt;
}

int n, k;
int a[55], b[55], y[55];
vector<pair<int, int> > nei[200005];
vector<int> lsa, lsb;
int jc[100005];
ll suf[55];
map<ll, int> dp[55][55];

int main() {
	scanf("%d%d", &n, &k);
	jc[0] = 1; cont(i, n) jc[i] = 1ll * jc[i - 1] * i % jt;
	cont(i, k) {
		scanf("%d%d%d", a + i, b + i, y + i); --y[i];
		lsa.pub(a[i]); lsb.pub(b[i]);
	}
	sort(all(lsa)); sort(all(lsb));
	int as = SZ(lsa);
	cont(i, k) {
		a[i] = lower_bound(all(lsa), a[i]) - lsa.begin();
		b[i] = lower_bound(all(lsb), b[i]) - lsb.begin();
		nei[a[i]].pub(mak(b[i], y[i]));
	}
	range(i, as - 1, 0, -1) {
		suf[i] = suf[i + 1];
		loop(j, SZ(nei[i])) suf[i] |= 1ll << nei[i][j].first;
	}
	dp[0][0][0] = 1;
	loop(i, as) loop(j, i + 1) foreach(it, dp[i][j]) {
		add(dp[i + 1][j][it->first & suf[i + 1]], it->second);
		loop(k, SZ(nei[i])) {
			int to = nei[i][k].first;
			if(!((it->first >> to) & 1)) {
				add(dp[i + 1][j + 1][(it->first | (1ll << to)) & suf[i + 1]], 1ll * it->second * nei[i][k].second % jt);
			}
		}
	}
	int ans = 0;
	loop(i, as + 1) foreach(it, dp[as][i]) {
		ans = (ans + 1ll * it->second * jc[n - i]) % jt;
	}
	printf("%d\n", ans); return 0;
}