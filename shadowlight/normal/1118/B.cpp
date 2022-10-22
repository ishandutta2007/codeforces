#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("B.in", "r", stdin);
	//freopen("B.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i % 2 == 0) {
			sum3 += a[i];
		} else {
			sum4 += a[i];
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		sum3 -= a[i];
		swap(sum3, sum4);
		if (sum1 + sum3 == sum2 + sum4) {
			res++;
		}
		sum1 += a[i];
		swap(sum1, sum2);
	}
	cout << res << "\n";
}