#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n;
vector<int> a;

void read() {
	cin >> n;
	a.resize(n);
	for (auto &i : a)
		cin >> i;
}

vector<int> ans;

void run() {
	for (int i = 0; i < 2 * n; i++)
		a.push_back(a[i]);
	multiset<int> have;
	int r = 0;
	for (int i = 0; i < n; i++) {
		while (r < (int)a.size() && (have.empty() || *(--have.end()) <= 2 * a[r])) {
			have.insert(a[r++]);
		}
		if (r == (int)a.size()) {
			ans.push_back(-1);
		}
		else {
			ans.push_back(r - i);
		}
		have.erase(have.find(a[i]));
	}
}

void write() {
	for (auto i : ans)
		cout << i << " ";
	cout << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}