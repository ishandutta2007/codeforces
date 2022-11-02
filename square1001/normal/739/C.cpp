#include <map>
#include <set>
#include <vector>
#include <iostream>
using namespace std;
int n, q, l, r, d, a[300009], sgn[300009]; long long diff[300009]; set<int> s; map<int, int> g;
void setsgn(int x) {
	if (diff[x] == 0) sgn[x] = 0;
	else if (diff[x] < 0) sgn[x] = 1;
	else sgn[x] = -1;
}
void add(int x) {
	if (!s.count(x)) {
		set<int>::iterator it = s.lower_bound(x);
		int r = *it, l = *(--it);
		g[l - r]--; if (!g[l - r]) g.erase(l - r);
		g[l - x]++; g[x - r]++; s.insert(x);
	}
}
void erase(int x) {
	if (s.count(x)) {
		s.erase(x);
		set<int>::iterator it = s.lower_bound(x);
		int r = *it, l = *(--it); g[l - r]++;
		g[l - x]--; if (!g[l - x]) g.erase(l - x);
		g[x - r]--; if (!g[x - r]) g.erase(x - r);
	}
}
void setdiff(int i, long long x) {
	diff[i] = x; setsgn(i);
	if (sgn[i] == 0) add(i), add(i + 1);
	else {
		if (i >= 1) {
			if (sgn[i - 1] <= sgn[i] && sgn[i - 1] != 0) erase(i);
			else add(i);
		}
		if (i < n - 1) {
			if (sgn[i] <= sgn[i + 1] && sgn[i + 1] != 0) erase(i + 1);
			else add(i + 1);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n; s.insert(0); s.insert(n - 1);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n - 1; i++) {
		diff[i] = a[i + 1] - a[i];
		setsgn(i);
		if (sgn[i] == 0) s.insert(i), s.insert(i + 1);
	}
	for (int i = 1; i < n - 1; i++) {
		if (sgn[i - 1] == 1 && sgn[i] == -1) s.insert(i);
	}
	vector<int> v(s.begin(), s.end());
	for (int i = 1; i < v.size(); i++) g[v[i - 1] - v[i]]++;
	cin >> q;
	while (q--) {
		cin >> l >> r >> d; l--;
		if (l >= 1) setdiff(l - 1, diff[l - 1] + d);
		if (r < n) setdiff(r - 1, diff[r - 1] - d);
		cout << -(*g.begin()).first + 1 << endl;
	}
	return 0;
}