#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <pair <int, int> > a;
	int x;
	cin >> x;
	a.push_back({x, 1});
	for (int i = 1; i < n; i++) {
		cin >> x;
		if (x != a.back().first) {
			a.push_back({x, 1});
		} else {
			a.back().second++;
		}
	}
	int res = 0;
	for (int i = 0; i < (int) a.size() - 1; i++) {
		res = max(res, min(a[i].second, a[i + 1].second));
	}
	cout << 2 * res << "\n";
}