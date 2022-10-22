#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("C.in", "r", stdin);
	//freopen("C.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector <int> d;
	int pr;
	cin >> pr;
	for (int i = 1; i < n; i++) {
		int x;
		cin >> x;
		d.push_back(x - pr);
		pr = x;
	}
	sort(d.rbegin(), d.rend());
	ll sum = 0;
	for (int x : d) {
		sum += x;
	}
	for (int i = 0; i < k - 1; i++) {
		sum -= d[i];
	}
	cout << sum << "\n";
}