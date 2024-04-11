#include <bits/stdc++.h>
using namespace std;
#define maxn 500010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
#define fi first
#define pi pair<int, ll>
#define se second
#define mp make_pair
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
// head
int calc(pi a) {
	if (a.fi == 0 && a.se == 0) return 0;
	if (a.fi > 0 && a.se >= 0) return 1;
	if (a.fi <= 0 && a.se > 0) return 2;
	if (a.fi < 0 && a.se <= 0) return 3;
	if (a.fi >= 0 && a.se < 0) return 4;
//	cout << "WA" << endl;
}
bool cmp (pi a, pi b) {
	if (calc(a) != calc(b)) return calc(a) < calc(b);
	return 1ll * a.fi * b.se < 1ll * a.se * b.fi; 
}
struct th {
	pi dir;
	db len;
	bool operator < (const th &r) const {
		if (cmp(dir, r.dir)) return 1;
		if (cmp(r.dir, dir)) return 0;
		return len < r.len;
	}
}q[maxn];
db w[maxn];
const db eps = 1e-10;
multiset<db> r;
#define iter multiset<db>::iterator
db cur[maxn];
db inr[maxn];
db sm[maxn];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		q[i].dir = mp(x, y);
		q[i].len = sqrt(1ll * x * x + 1ll * y * y);
	}
	sort(q + 1, q + n + 1);
	for (int i = 1; i <= n; ) {
		int j = i;
		while (j <= n && !cmp(q[i].dir, q[j].dir)) j++;
		for (int s = j - 1; s >= i; s--) {
			int cs = (j - 1 - s);
			int tr = (k - 1) - 2 * cs;
			w[s] = q[s].len * tr;
			r.insert(w[s]);
		}
		i = j;
	}
	iter h = --r.end();
	db ans = 0;
	for (int j = 1; j <= k; j++)
		ans += (*h), h--;
//	cout << ans << endl;
	for (int i = 1; i <= n; ) {
		int j = i;
		while (j <= n && !cmp(q[i].dir, q[j].dir)) j++;
		if (j - i >= k / 2 + 1) {
			int cnt = 0;
			for (int s = i; s < j; s++)
				cur[++cnt] = q[s].len, 
				r.erase(r.lower_bound(w[s] - eps));
		//	cout << "!!!" << j - i << endl;
			int rc = 0;
			iter q = r.end();
			for (int s = 0; s < k && q != r.begin(); s++) {
				q--;
				inr[++rc] = *q;
			}
			for (int j = 1; j <= rc; j++)
				sm[j] = sm[j - 1] + inr[j];
			// r 
			int lt = 0, rt = cnt + 1;
			int cs = 0;
			db tot = 0, ftot = 0;
			while (cs < cnt && cs < k) {
				int rd = (cnt - rt + 1);
				if (rd < k / 2) {
					rt--;
					tot += cur[rt] * (k - 1 - rd * 2);
				}
				else {
					lt++;
					tot += cur[lt] * (k - 1 - rd * 2) - 2 * ftot;
					ftot += cur[lt];
				}
				cs++;
				if (k - cs <= rc) {
					db nans = tot + sm[k - cs];
				//	cout << "CHOOSE " << cs << ' ' << nans << endl;
					ans = max(ans, nans);
				}
			}
			for (int s = i; s < j; s++)
				r.insert(w[s]);
		}
		i = j; 
	} 
	printf("%.20lf\n", ans);
	return 0;
}