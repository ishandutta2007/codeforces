#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

mt19937 rnd(228);

map<pair<int, int>, int> mem;
int Q = 2048 * 2 + 170;
int query(int a, int b) {
	if (a > b) swap(a, b);
	if (mem.count({a, b})) return mem[{a, b}];
	Q--;
	assert(Q >= 0);
	cout << "? " << a + 1 << " " << b + 1 << endl;
	int ans;
	cin >> ans;
	mem[{a, b}] = ans;
	return ans;
}

void outAns(vector<int> ans) {
	cout << "! ";
	for (auto i : ans) {
		cout << i << " ";
	}
	cout << endl;
	exit(0);
}

int getBit(int x) {
	return __builtin_popcount(x);
}

int findZero(int pos, vector<int> have) {
	int val = 1e9;
	vector<int> nhave = {};
	vector<int> check;
	for (int i = 0; i < (int)have.size(); i++) {
		if (have[i] == pos) continue;
		if (getBit(query(have[i], pos)) == 1) {
			check.push_back(query(have[i], pos));
		}
		if (query(have[i], pos) > val) continue;
		if (query(have[i], pos) < val) val = query(have[i], pos), nhave = {};
		nhave.push_back(have[i]); 
	}
	sort(all(check));
	check.resize(unique(all(check)) - check.begin());
	if (check.size() > 1) return pos;
	if (nhave.size() == 1) return nhave[0];
	return findZero(nhave[rnd() % (int)nhave.size()], nhave);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int val = 1e9, posNow = 0;
	for (int i = 0; i < Q - 2 * n; i++) {
		int a = rnd() % n;
		int b = rnd() % n;
		if (a == b) {
			i--;
			continue;
		}
		if (getBit(query(a, b)) < val) {
			val = getBit(query(a, b));
			posNow = a;
		}
	}
	vector<int> have(n);
	iota(all(have), 0);
	int zero = findZero(posNow, have);
	//cout << "zero = " << zero << endl;
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		if (i == zero) continue;
		ans[i] = query(i, zero);
	}
	outAns(ans);
	return 0;
}