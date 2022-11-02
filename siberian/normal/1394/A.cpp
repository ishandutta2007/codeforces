#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}
#define int ll
const int N = 1e5 + 10;
int n, d, m;
int a[N];
ll pref[N];

void read() {
	cin >> n >> d >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	pref[0] = 0;
	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1] + a[i - 1];
	}
	/*cout << "a = " << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;*/
}

ll get(int l, int r) {
	if (r < l) return 0;
	return pref[r] - pref[l - 1];
}

ll ans;

void relax(int cnt) {
	if (cnt > 1 && (cnt - 1) * (d + 1) + 1 > n) return; 
	ll sumBest = get(n - cnt + 1, n);
	int pos = upper_bound(a, a + n, m) - a;
	chkmin(pos, n - cnt);
	//cout << "pos = " << pos << endl;
	if (pos + cnt * (d + 1) < n) return;
	int need = n - (cnt - 1) * (d + 1) - 1;
	chkmin(need, pos);
	//cout << (cnt - 1) * (d + 1) + 1 << endl;
	//cout << "need = " << need << endl;
	ll sumL = get(pos - need + 1, pos);
	//cout << cnt << " " << sumL << " " << sumBest << endl;
	chkmax(ans, sumL + sumBest);
}

void run() {
	ans = 0;
	if (a[n - 1] <= m) {
		ans = pref[n];
	}
	for (int cnt = 1; cnt <= n; cnt++) {
		relax(cnt);
	}
}

void write() {
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
	read();
	run();
	write();
	return 0;
}