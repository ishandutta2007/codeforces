#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}
#define int ll

vector<vector<int>> gen(int n) {
	vector<vector<int>> a(n, vector<int> (n, 0));
    for (int i = 0; i < n; i++) {
    	if ((i & 1) == 0) {
    		for (int j = 0; j < n; j++) {
    			a[i][j] = (1LL << (i + j + 1));
    		}
    	}
    }
    return a;
}

void outTable(vector<vector<int>> a) {
	for (auto i : a) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << "\n";
	}
	cout.flush();
}

int n;
vector<vector<int>> a;

void read() {
	cin >> n;
	a = gen(n);
	outTable(a);
}

void outAns(vector<pair<int, int>> ans) {
	for (auto i : ans) {
		cout << i.first + 1 << " " << i.second + 1 << "\n";
	}
	cout.flush();
}

int getLog(int x) {
	int ans = 0;
	while (x) {
		ans++;
		x /= 2;
	}
	return ans - 1;
}

void solve() {
	int sum;
	cin >> sum;
	vector<pair<int, int>> ans;
	ans.push_back({0, 0});
	sum -= 2;
	int x = 0, y = 0;
	while (ans.back() != make_pair(n - 1, n - 1)) {
		if (x % 2 == 1 && x + 1 < n && ((sum >> getLog(a[x + 1][y])) & 1)) {
			x++;
		} else if (x % 2 == 0 && y + 1 < n && ((sum >> getLog(a[x][y + 1])) & 1)) {
			y++;
		} else if (x % 2 == 0) {
			x++;
		} else {
			y++;
		}
		sum -= a[x][y];
		ans.push_back({x, y});
	}
	outAns(ans);
}

void run() {
	int q;
	cin >> q;
	while (q--) {
		solve();
	}
}

void write() {

}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
	//brute();
	read();
	run();
	write();
	return 0;
}