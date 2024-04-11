#include <set>
#include <string>
#include <iostream>
using namespace std;
int n, q, l, r, bit[262156]; string s, t; set<int> st[129];
void add(int pos, int val) {
	for (int i = pos + 1; i <= 262144; i += i & (-i)) bit[i] += val;
}
int sum(int pos) {
	int ret = 0;
	for (int i = pos; i >= 1; i -= i & (-i)) ret += bit[i];
	return ret;
}
int bss(int pos) {
	if (pos == 0) return 0;
	int sum = 0, cur = 0;
	for (int i = 17; i >= 0; i--) {
		if (sum + bit[cur + (1 << i)] < pos) {
			cur += 1 << i;
			sum += bit[cur];
		}
	}
	return cur + 1;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> q >> s;
	for (int i = 0; i < n; i++) {
		st[s[i]].insert(i);
		add(i, 1);
	}
	for (int i = 0; i < q; i++) {
		cin >> l >> r >> t; l--;
		int pl = bss(l), pr = bss(r);
		set<int>::iterator it = st[t[0]].lower_bound(pl);
		while (it != st[t[0]].end() && *it < pr) {
			add(*it, -1);
			it = st[t[0]].erase(it);
		}
	}
	for (int i = 0; i < n; i++) {
		if (sum(i + 1) - sum(i)) cout << s[i];
	}
	cout << endl;
	return 0;
}