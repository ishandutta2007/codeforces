#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

int n, k;
vector<int> l, r, a;

inline bool read() {
	if(!(cin >> n >> k))
		return false;
	l.resize(n);
	r.resize(n);
	a.resize(n);
	
	fore(i, 0, n)
		cin >> l[i] >> r[i] >> a[i];
	
	return true;
}

inline void solve() {
	vector<li> d(n + 1, INF64);
	d[0] = 0;
	
	li ans = INF64;
	fore(i, 0, n) {
		li rem = k, total = d[i];
		for (int j = i; j < n; j++) {
			li cntReloads = (max(0LL, a[j] - rem) + k - 1) / k;
			if (cntReloads > r[j] - l[j])
				break;
			
			li newRem = (rem + cntReloads * k) - a[j];
			total += a[j];
			if (j + 1 < n) {
				if (l[j] + cntReloads < l[j + 1])
					d[j + 1] = min(d[j + 1], total + newRem);
			} else
				ans = min(ans, total);
			rem = newRem;
		}
	}
	if (ans > INF64 / 2)
		ans = -1;
	cout << ans << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
	if(read()) {
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}