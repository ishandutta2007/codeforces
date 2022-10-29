#include <bits/stdc++.h>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i,l,r) for (int i = int(l); i <= int(r); i++)
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define x first
#define y second

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

int n, m, k;
const int N = 200 * 1000 + 5;
int c[N];

int like[N][2];

inline bool read() {
	scanf("%d%d%d", &n, &m, &k);
	forn (i, n)
		scanf("%d", &c[i]);
	forn (it, 2) {
		int k;
		scanf("%d", &k);
		forn (i, k) {
			int a;
			scanf("%d", &a);
			a--;
			like[a][it] = true;
		}
	}
	return true;
}
   
int cnt[4 * N];
li sum[4 * N];

vector<int> cx;

int get(int x) {
	return lower_bound(all(cx), x) - cx.begin();
}

void inc(int id, int l, int r, int pos, int d) {
	if (l + 1 == r) {
		cnt[id] += d;
		sum[id] += d * cx[l];
		return;
	}
	int mid = (l + r) / 2;
	if (pos < mid)
		inc(2 * id + 1, l, mid, pos, d);
	else
		inc(2 * id + 2, mid, r, pos, d);
	cnt[id] = cnt[2 * id + 1] + cnt[2 * id + 2];
	sum[id] = sum[2 * id + 1] + sum[2 * id + 2];
}

li getfirst(int id, int l, int r, int k) {
	if (cnt[id] == k)
		return sum[id];
	if (k == 0)
		return 0;
	if (r - l == 1) {
		return li(k) * cx[l];
	}
	int mid = (l + r) / 2;
	if (cnt[2 * id + 1] >= k)
		return getfirst(2 * id + 1, l, mid, k);
	return getfirst(2 * id + 1, l, mid, cnt[2 * id + 1]) + getfirst(2 * id + 2, mid, r, k - cnt[2 * id + 1]);
}

inline void solve() {   
	if (k > m) {
		cout << -1 << endl;
		return;
	}
	
	forn (i, n)
		cx.pb(c[i]);
	sort(all(cx));
	cx.resize(unique(all(cx)) - cx.begin());
	
	forn (i, n)
		inc(0, 0, sz(cx), get(c[i]), +1);
	
	vector<int> both, a, b;
		
	forn (i, n) {
		if (like[i][0] && like[i][1])
			both.pb(c[i]);
		if (like[i][0] && !like[i][1])
			a.pb(c[i]);
		if (!like[i][0] && like[i][1])
			b.pb(c[i]);
	}
	
	sort(all(both));
	sort(all(a));
	sort(all(b));
	
	li ans = INF64;
	li leftsum = 0;
	li suma = 0, sumb = 0;
	
	forn (i, k) {
		if (i < sz(a)) {
			inc(0, 0, sz(cx), get(a[i]), -1);
			suma += a[i];
		}
		if (i < sz(b)) {
			inc(0, 0, sz(cx), get(b[i]), -1);
			sumb += b[i];
		}
	}
	
			
	
	forn (i, min(k, sz(both)) + 1) {
		int need = k - i;
		if (need <= sz(a) && need <= sz(b)) {
			li curans = leftsum + suma + sumb;
			int lm = m - i - 2 * need;
			if (lm >= 0) {
				curans += getfirst(0, 0, sz(cx), lm);
				ans = min(ans, curans);
			}
		}
		if (need <= sz(a) && need) {
			suma -= a[need - 1];
			inc(0, 0, sz(cx), get(a[need - 1]), +1);
		}
		if (need <= sz(b) && need) {
			sumb -= b[need - 1];
			inc(0, 0, sz(cx), get(b[need - 1]), +1);
		}
		if (i < sz(both)) {
			leftsum += both[i];		
			inc(0, 0, sz(cx), get(both[i]), -1);
		}
	}
	
	if (ans == INF64)
		ans = -1;

	cout << ans << endl;
}

int main()
{
#ifdef SU2
	assert(freopen("input.txt", "r", stdin));
	assert(freopen("output.txt", "w", stdout));
#endif

	cout << setprecision(25) << fixed;
	cerr << setprecision(10) << fixed;

	srand(int(time(NULL)));

	assert(read());
	solve();

#ifdef SU2
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}