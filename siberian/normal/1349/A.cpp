#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) (x).begin(), (x).end()
template <typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}
#define int ll
const int MAXA = 2e5 + 10;

int lp[MAXA];
vector<int> pr;

void build() {
	for (int i = 2; i < MAXA; i++) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; j < (int) pr.size() && pr[j] * i < MAXA && pr[j] <= lp[i]; j++) {
			lp[pr[j] * i] = pr[j];
		}
	}
}

int n;

vector<int> have[MAXA];

void add(int x) {
	while (lp[x]) {
		int cnt = 0;
		int d = lp[x];
		while (lp[x] == d) {
			x /= lp[x];
			cnt++;
		}
		have[d].push_back(cnt);
	}
}

void read() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		add(x);
	}
}

ll ans;

void run() {
	ans = 1;
	for (int i = 2; i < MAXA; i++) {
		sort(all(have[i]));
		if (have[i].size() <= n - 2) continue;
		int x = have[i][have[i].size() - n + 1];
		while (x--) {
			ans *= i;
		}
	}
}

void write() {
	cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.setf(ios::fixed), cout.precision(20);
    build();
    read();
    run();
    write();
    return 0;
}