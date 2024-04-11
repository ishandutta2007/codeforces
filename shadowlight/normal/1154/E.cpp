#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("E.in", "r", stdin);
	//freopen("E.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector <int> a(n);
	set <pair <int, int> > q;
	set <int> ex;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		q.insert({a[i], i});
		ex.insert(i);
	}
	vector <int> res(n, 0);
	int tp = 1;
	while (ex.size()) {
		auto t = *q.rbegin();
		int pos = t.second;
		auto it = ex.upper_bound(pos);
		for (int i = 0; i < k + 1; i++) {
			if (it == ex.begin()) {
				break;
			}
			it--;
			res[*it] = tp;
			q.erase({a[*it], *it});
			ex.erase(it);
			it = ex.upper_bound(pos);
		}
		for (int i = 0; i < k; i++) {
			if (it == ex.end()) {
				break;
			}
			res[*it] = tp;
			q.erase({a[*it], *it});
			ex.erase(it++);
		}
		tp = 3 - tp;
	}
	for (int i = 0; i < n; i++) {
		cout << res[i];
	}
}