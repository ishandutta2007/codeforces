#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define int			ll
#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 1e18;

int n, m, tn, ps[MAXN], s, ss[MAXN], ps_d[MAXN], ss_d[MAXN], S[MAXN], TPS[MAXN], TSS[MAXN];
vector<int> vec[MAXN], P;
vector<pll> Q;

inline int ind(int x) {
	return lower_bound(all(P), x) - P.begin();
}

inline void solve() {
	P.clear();
	Q.clear();
	s = 0;
	for (int i = 0; i < max(tn, n) + 10; i++) {
		S[i] = ps[i] = ss[i] = ps_d[i] = ss_d[i] = 0;
		vec[i].clear();
		TPS[i] = TSS[i] = -INF;
	}

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int x, p;
		cin >> x >> p;
		Q.push_back({x, p});
		P.push_back(x);
		P.push_back(x - p);
		P.push_back(x + p);
	}

	P.push_back(-INF);
	sort(all(P));
	P.resize(unique(all(P)) - P.begin());

	tn = P.size() - 1;

	for (int i = 0; i < max(tn, n) + 10; i++) {
		S[i] = ps[i] = ss[i] = ps_d[i] = ss_d[i] = 0;
		vec[i].clear();
		TPS[i] = TSS[i] = -INF;
	}
	for (auto [x, p] : Q) {
		int i = ind(x);
		ps[i]++;
		ps_d[i] += p;
		ss[i]++;
		ss_d[i] += p;
		S[i] -= p;
			
		i = ind(x + p);
		ps[i]--;
	
		i = ind(x - p + 1) - 1;
		ss[i]--;
	}

	ll s = 0, cnt = 0;
	for (int i = 1; i <= tn; i++) {
		if (i > 1) s -= cnt * (P[i] - P[i - 1]);
		s += ps_d[i];
		cnt += ps[i];
	
		S[i] += s;
	}


	int mn = INF, mx = -INF;
	s = cnt = 0;
	for (int i = tn; i > 0; i--) {
		if (i < tn) s -= cnt * (P[i + 1] - P[i]);
		s += ss_d[i];
		cnt += ss[i];

		S[i] += s;	
	}

	for (int i = 1; i <= tn; i++) {
		TPS[i] = TPS[i - 1];
		if (S[i] > m) {
			mn = min(mn, P[i]);
			mx = max(mx, P[i]);
			TPS[i] = max(TPS[i], S[i] - m - P[i]);
		}
	}

	for (int i = tn; i > 0; i--) {
		TSS[i] = TSS[i + 1];
		if (S[i] > m) {
			mn = min(mn, P[i]);
			mx = max(mx, P[i]);
			TSS[i] = max(TSS[i], S[i] - m + P[i]);
		}
	}

	if (mn == INF) {
		for (int i = 1; i <= n; i++)
			cout << 1;
		cout << endl;
		return;
	}

	for (auto [x, p] : Q) {
		int i = ind(x);
		if (mn <= x - p || mx >= x + p) {
			cout << 0;
			continue;
		}

		if (TPS[i] <= p - x && TSS[i] <= p + x)
			cout << 1;
		else
			cout << 0;
	}

	cout << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}