#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <deque>


using namespace std;


#define ll long long
#define all(a) a.begin(), a.end()


const int maxn = 1e5;


vector<int> mn(maxn + 1);
vector<int> mx(maxn + 1);


void cnt_mn_mx() {
	mn[1] = 0;
	mx[1] = 0;
	for (int i = 2; i <= maxn; ++i) {
		if (i % 2 == 0) {
			mn[i] = 2 * mn[i / 2] + i / 2;
			mx[i] = 2 * mx[i / 2] + i / 2;
		}
		else {
			mn[i] = 2 * mn[i / 2] + i / 2;
			mx[i] = 2 * mx[i / 2] + i / 2 + 1;
		}
	}
}


void prnt() {
	cnt_mn_mx();
	for (int i = maxn - 100; i <= maxn; ++i) {
		cout << i << " " << mn[i] << " " << mx[i] << " " << mx[i] - mn[i] + 1 << "\n";
	}
}


string s;


bool try_to_sort(int l, int r, int &ps, vector<int> &res) {
	if (l + 1 == r) {
		res.push_back(l);
		return true;
	}
	int m = (l + r) / 2;
	vector<int> x1, x2;
	if (!try_to_sort(l, m, ps, x1) || !try_to_sort(m, r, ps, x2)) {
		return false;
	}
	int i = 0;
	int j = 0;
	while (i < x1.size() && j < x2.size() && ps < s.size()) {
		if (s[ps++] == '0') {
			res.push_back(x1[i++]);
		}
		else {
			res.push_back(x2[j++]);
		}
	}
	if (i < x1.size() && j < x2.size()) {
		return false;
	}
	while (i < x1.size()) {
		res.push_back(x1[i++]);
	}
	while (j < x2.size()) {
		res.push_back(x2[j++]);
	}
	return true;
}



bool try_with_n(int n, vector<int> &res) {
	vector<int> p;
	res.resize(n);
	int ps = 0;
	if (!try_to_sort(0, n, ps, p)) {
		return false;
	}
	if (ps < s.size()) {
		return false;
	}
	for (int i = 0; i < n; ++i) {
		res[p[i]] = i;
	}
	return true;
}


int32_t main() {
	// prnt();
	cin >> s;
	vector<int> res;
	int k = s.size() / 7;
	for (int i = 0; ; ++i) {
		int x = max(1, k - i);
		int y = max(1, k + i);
		if (try_with_n(x, res)) {
			break;
		}
		if (try_with_n(y, res)) {
			break;
		}
	}
	cout << res.size() << "\n";
	for (auto x : res) {
		cout << x + 1 << " ";
	}
	cout << "\n";
	return 0;
}