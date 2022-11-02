#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
#define int ll
int n, m;
vector<vector<int> > a;

void read() {
	cin >> n >> m;
	a.assign(n, vector<int> (m, 0));
	for (auto &i : a)
		for (auto &j : i)
			cin >> j;
}

int get(const vector<int> & a, const vector<int> & need) {
	vector<int> cost(n, n);
	for (int i = 0; i < n; i++) {
		int pos = lower_bound(all(need), a[i]) - need.begin();
	//	cout << pos << endl;
		//if (pos != n)
	//		cout << "a =  " << a[pos ] << " " << a[i] << endl;
		if (pos == n || need[pos] != a[i]) continue;
	//	cout << "puhh" << endl;
		int len;
		if (i >= pos)
			len = i - pos;
		else
			len = i + n - pos;
		cost[len]--; 
	//	cout << "len = " << len << endl;
	}
	//cout << "Cost = " << endl;
	//for (auto i : cost)
	//	cout << i << " ";
	//cout << endl;
	int ans = 1e9;
	for (int i = 0; i < n; i++)
		chkmin(ans, cost[i] + i);
	return ans;
}

int ans;

void run() {
	for (int j = 0; j < m; j++) {
		vector<int> have;
		for (int i = 0; i < n; i++)
			have.push_back(a[i][j]);
		vector<int> need;
		for (int i = 0; i < n; i++) 
			need.push_back(j + 1 + m * i);
		
	/*	cout << "have = " << endl;
		for (auto j : have)
			cout << j << " ";
		cout << endl;
		cout << "need = " << endl;
		for (auto j : need)
			cout << j << " ";
		cout << endl;
		cout << "cost = " << get(have, need) << endl;
		cout << endl; */
		ans += get(have, need);
	}
}

void write() {
	cout << ans << endl;
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