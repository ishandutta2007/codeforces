#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	multiset<int> S;
	long long sum = 0;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i];
		++cnt;
		S.insert(a[i]);
		if (sum < 0) {
			--cnt;
			sum -= *S.begin();
			S.erase(S.begin());
		}
	}
	cout << cnt << "\n";
	return 0;
}