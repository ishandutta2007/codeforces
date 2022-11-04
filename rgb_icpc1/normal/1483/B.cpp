#include <bits/stdc++.h>

using namespace std;

void err_out() { cerr << endl; }
template<typename hd, typename... tl> void err_out(hd a, tl... b) { cerr << ' ' << a; err_out(b...); }
#ifdef LOCAL
#define err(...) cerr << "[" << #__VA_ARGS__ << "]:", err_out(__VA_ARGS__)
#else
#define err(...) 42
#endif

template<typename hd, typename tl> void chkmin(hd& a, tl b) { if(b < a) a = b; }
template<typename hd, typename tl> void chkmax(hd& a, tl b) { if(a < b) a = b; }

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

#define endl '\n'
using llint = long long;

typedef pair<int, int> pii;

const int MX = 100005;
const int INF = 1000000005;
struct WinnerTree {
	pii v[MX * 4];
	int n;

	void build(int *a, int an) {
		int i;
		for (n = 1; n < an; n *= 2);
		for (i = 0; i < an; i++) v[n + i] = {a[i], i};
		for (i = an; i < n; i++) v[n + i] = {a[0], 0};
		for (i = n - 1; i > 0; i--) v[i] = min(v[i * 2], v[i * 2 + 1]);
	}

	void up(int i, int val) {
		i += n;
		v[i].first = val;
		for (i /= 2; i; i /= 2) v[i] = min(v[i * 2], v[i * 2 + 1]);
	}

	pii get(int st, int en) {
		pii rlt = {INF, -1};
		st += n, en += n;
		while (st < en) {
			if (st & 1) rlt = min(rlt, v[st]);
			if (en & 1) rlt = min(rlt, v[en - 1]);
			st = (st + 1) / 2;
			en /= 2;
		}
		return rlt;
	}
} WT;

int a[MX], g[MX], l[MX], r[MX];
vector<int> ans;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);
	int Tc;
	for (cin >> Tc; Tc--;) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		g[0] = __gcd(a[0], a[n - 1]); for (int i = 1; i < n; i++) g[i] = __gcd(a[i], a[i - 1]);
		l[0] = n - 1; for (int i = 1; i < n; i++) l[i] = i - 1;
		r[n - 1] = 0; for (int i = 1; i < n; i++) r[i - 1] = i;
		WT.build(g, n);
		int pos = 1; ans.clear();
		while (1) {
			pii rlt = WT.get(pos, n);
			if (rlt.first == 1) {
//				cout << rlt.first << ' ' << rlt.second + 1 << endl;
				int id = rlt.second;
				ans.push_back(id + 1);
				r[l[id]] = r[id];
				l[r[id]] = l[id];
				g[r[id]] = __gcd(a[r[id]], a[l[id]]);
				WT.up(r[id], g[r[id]]);
				WT.up(id, INF);
				pos = r[r[id]];
				continue;
			}
			rlt = WT.get(0, pos);
			if (rlt.first == 1) {
//				cout << rlt.first << ' ' << rlt.second + 1 << endl;
				int id = rlt.second;
				ans.push_back(id + 1);
				r[l[id]] = r[id];
				l[r[id]] = l[id];
				g[r[id]] = __gcd(a[r[id]], a[l[id]]);
				WT.up(r[id], g[r[id]]);
				WT.up(id, INF);
				pos = r[r[id]];
				continue;
			}
			break;
		}
		cout << ans.size();
		for (auto v : ans) cout << ' ' << v; cout << endl;
	}

	return 0;
}