#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;

int n, m, k;
int c[N];
int f1[N], f2[N];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> c[i];
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int x;
		cin >> x;
		f1[x - 1] = 1;
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		int x;
		cin >> x;
		f2[x - 1] = 1;
	}
	vector<int> w, a, b;
	vector<int> d;
	for (int i = 0; i < n; i++) {
		if (f1[i] && f2[i]) w.pb(c[i]); else
		if (f1[i]) a.pb(c[i]); else
		if (f2[i]) b.pb(c[i]); else d.pb(c[i]);
	}
	sort(w.begin(), w.end());
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(d.begin(), d.end());

	vector<long long> ww, aa, bb, dd;
	ww.pb(0);
	aa.pb(0);
	bb.pb(0);
	dd.pb(0);
	for (int i = 0; i < w.size(); i++) ww.pb(ww.back() + w[i]);
	for (int i = 0; i < a.size(); i++) aa.pb(aa.back() + a[i]);
	for (int i = 0; i < b.size(); i++) bb.pb(bb.back() + b[i]);
	for (int i = 0; i < d.size(); i++) dd.pb(dd.back() + d[i]);

	long long ans = 1e18 + 1;

	for (int i = 0; i <= w.size(); i++) {
		long long cost = ww[i];
		int need = max(0, k - i);
		if (need > a.size() || need > b.size() || i + need * 2 > m) continue;
		cost += aa[need];
		cost += bb[need];

		int re = m - i - 2 * need;

		if (a.size() - need + b.size() - need + d.size() < re) continue;

		if (re > 0) {

		int l = 0;
		int r = 1e9 + 1;
		while (l < r) {
			int mid = (l + r) / 2;
			int cnt = 0;
			int h = upper_bound(a.begin(), a.end(), mid) - a.begin();
			cnt += max(0, h - need);
			h = upper_bound(b.begin(), b.end(), mid) - b.begin();
			cnt += max(0, h - need);
			h = upper_bound(d.begin(), d.end(), mid) - d.begin();
			cnt += max(0, h);
			if (cnt >= re) r = mid; else l = mid + 1;
		}
		{
			int mid = l;
			int cnt = 0;

			int h = upper_bound(a.begin(), a.end(), mid) - a.begin();
			cnt += max(0, h - need);
			if (h > need) cost += aa[h] - aa[need];

			h = upper_bound(b.begin(), b.end(), mid) - b.begin();
			cnt += max(0, h - need);
			if (h > need) cost += bb[h] - bb[need];

			h = upper_bound(d.begin(), d.end(), mid) - d.begin();
			cnt += max(0, h);
			cost += dd[h];

			if (cnt > re) cost -= mid * 1ll * (cnt - re);
		}
		}


		ans = min(ans, cost);
	}
	if (ans > 1e17) ans = -1;
	cout << ans << endl;
	return 0;
}