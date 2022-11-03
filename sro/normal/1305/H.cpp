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

int n, m, q, ans;
ll t;
int l[100005], r[100005];
int p[100005], s[100005];
int sc[100005];
bool qd[100005];

ll trytain(int l, int r, ll rem) {
	if (!rem) return 0;
	int xju = sc[l] - sc[r], ks = r - l;
	if (1ll * ks * xju <= rem) {
		circ(i, l, r) sc[i] = sc[l];
		return rem - ks * xju;
	}
	ll ts = rem / ks; rem %= ks;
	circ(i, l + 1, r) sc[i] += ts + (i - l - 1 < rem);
	return 0;
}

bool canpip(int l[], int w[], int ls, int ws) {
	int ptr = 0;
	ll wh = 0, wp = 0;
	range(i, ws, 1, -1) {
		wh += w[i];
		while (ptr < ls && l[ptr + 1] <= ws - i + 1) wp += l[++ptr];
		if (wh > wp + 1ll * (ws - i + 1) * (ls - ptr)) return 0;
	}
	return 1;
}

bool check(int mid, int hsc = -1) {
	memset(sc, -1, sizeof(sc));
	cont(i, q) sc[p[i]] = s[i];
	sc[m + 1] = 0;
	ll ac = 0;
	range(i, m, 1, -1) {
		if (!qd[i]) sc[i] = sc[i + 1];
		ac += sc[i];
	}
	bool me = 0;
	if (mid >= p[1]) {
		circ(i, p[1] + 1, mid) {
			if (qd[i] && s[1] != sc[i]) return 0;
			ac += s[1] - sc[i];
			sc[i] = s[1];
		}
		me = 1;
	} else if (~hsc) {
		cont(i, mid) {
			if (qd[i] && hsc != sc[i]) return 0;
			ac += hsc - sc[i];
			sc[i] = hsc;
		}
	}
	if (ac > t) return 0;
	ll na = t - ac;
	range(i, q, 1, -1) {
		na = trytain(max(p[i], mid), p[i + 1] - 1, na);
		if (!na || p[i] <= mid) break;
	}
	if (p[1] > mid) {
		if (me) na = trytain(mid, p[1] - 1, na);
		else if (!~hsc) {
			sc[0] = n;
			na = trytain(0, p[1] - 1, na);
			if (sc[1] != sc[mid]) return check(mid, sc[1]);
		} else {
			sc[0] = n;
			na = trytain(mid, p[1] - 1, na);
			na = trytain(0, p[1] - 1, na);
			if (sc[1] != sc[mid]) return check(mid, sc[1]);
		}
	}
	if (na > 0) return 0;
	sort(sc + 1, sc + m + 1);
	return canpip(sc, l, m, n) && canpip(r, sc, n, m);
}

int main() {
	scanf("%d%d", &n, &m);
	cont(i, n) scanf("%d%d", l + i, r + i);
	scanf("%d", &q);
	vector<pair<int, int> > fs;
	cont(i, q) {
		scanf("%d%d", p + i, s + i), qd[p[i]] = 1;
		fs.emb(p[i], s[i]);
	}
	sort(all(fs));
	loop(i, q) tie(p[i + 1], s[i + 1]) = fs[i];
	p[q + 1] = m + 1;
	scanf("%lld", &t);
	sort(l + 1, l + n + 1);
	sort(r + 1, r + n + 1);
	int lm = 0, rm = m + 1;
	while (rm - lm > 1) {
		int mid = (lm + rm) >> 1;
		if (check(mid)) lm = mid;
		else rm = mid;
	}
	if (!lm) return puts("-1 -1"), 0;
	if (lm >= p[1]) return printf("%d %d\n", lm, s[1]), 0;
	ans = lm;
	lm = s[1], rm = n + 1;
	while (rm - lm > 1) {
		int mid = (lm + rm) >> 1;
		if (check(ans, mid)) lm = mid;
		else rm = mid;
	}
	printf("%d %d\n", ans, lm);
	return 0;
}