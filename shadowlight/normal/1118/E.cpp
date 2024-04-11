#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("E.in", "r", stdin);
	//freopen("E.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector <pair <int, int> > all(n + 1);
	int last = 0;
	for (int i = 0; i < k; i++) {
		for (int j = i + 1; j < k; j++) {
			if (last >= n) break;
			all[last++] = {i, j};
			all[last++] = {j, i}; 
		}
		if (last >= n) break;
	}
	if (last < n) {
		cout << "NO\n";
		return 0; 
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		auto t = all[i];
		cout << t.first + 1 << " " << t.second + 1 << "\n";
	}
}