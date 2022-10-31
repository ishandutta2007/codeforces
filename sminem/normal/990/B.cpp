#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	sort(a+1, a+n+1);

	vector<int> b = {};

	for (int i=1; i<=n; i++) {
		while (b.size()) {
			if (a[i] > b.back() && a[i] <= b.back() + k) {
				b.pop_back();
			} else break;
		}
		if (b.size() == 0)
			b.push_back(a[i]);
		else if (b.back() > a[i] && b.back() <= a[i] + k) {

		} else {
			b.push_back(a[i]);
		}

		

	}

	cout << b.size();
}