#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define vi vector<int>
#define pb push_back
#define pi pair<int, ll>
#define ll long long
using namespace std;
#define int long long
int tot[2];
vi r[2];
int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}
int ax, ay;
void exgcd(int a, int b) {
	if (!b) {
		ax = 1, ay = 0;
		return ;
	}
	exgcd(b, a % b);
	pi fn = mp(ay, ax - (a / b) * ay);
	ax = fn.fi, ay = fn.se;
}
int ns;
vector<pair<ll, ll> > s[300007];
ll cal(int tp) {
	for (int i = 0; i < ns; i++)
		s[i].clear(); 
	ll ans = 0;
	sort(r[tp].begin(), r[tp].end());
	for (int i = tot[tp] - 1; i >= 0; i--) {
		int npl = lower_bound(r[tp].begin(), r[tp].end(), i) - r[tp].begin();
		if (npl == r[tp].size() || r[tp][npl] != i) {
			ans = i;
			break;
		}
	}
	exgcd(tot[tp] / ns, tot[tp ^ 1] / ns);
	ll nt = tot[tp] / ns;
	ll step = tot[tp ^ 1];
	ll bk = (ay % nt + nt) % nt;
	for (auto g : r[tp]) {
		ll nid = g % ns, ndis = (g - nid) / ns;
		s[nid].pb(mp(ndis * bk % nt, g));
	}
	for (auto g : r[tp ^ 1]) {
		ll nid = g % ns, ndis = (g % tot[tp] - nid) / ns;
		s[nid].pb(mp(ndis * bk % nt, g));
	}
	for (int i = 0; i < ns; i++) {
		if (s[i].empty()) {
			printf("-1\n");
			exit(0);
		}
		sort(s[i].begin(), s[i].end());
		s[i].pb(mp(s[i][0].first + tot[tp] / ns, 0));
		for (int j = 0; j < s[i].size() - 1; j++) {
			ll nans = (s[i][j + 1].fi - 1 - s[i][j].fi) * step + s[i][j].se;
			if (s[i][j + 1].fi - 1 > s[i][j].fi) ans = max(ans, nans);
			if (s[i][j].se >= tot[tp]) ans = max(ans, s[i][j].se);
			s[i][j + 1].se = min(s[i][j + 1].se, nans + step);
		}
	}
//	cout << ans << endl;
	return ans;
}
#undef int
int main() {
	cin >> tot[0] >> tot[1];
	ns = gcd(tot[0], tot[1]);
	if (ns > 3e5) {
		printf("-1\n");
		exit(0);
	}
	for (int i = 0; i < 2; i++) {
		int sz;
		cin >> sz;
		r[i].resize(sz);
		for (int j = 0; j < sz; j++)
			scanf("%lld", &r[i][j]);
		sort(r[i].begin(), r[i].end());
	}
	ll ans = max(cal(0), cal(1));
	cout << ans << endl;
	return 0;
}