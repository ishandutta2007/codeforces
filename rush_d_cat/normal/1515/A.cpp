#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t --) {
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		for (int i = 0; i < n; i ++) cin >> a[i];
		if (accumulate(a.begin(),a.end(),0) == x) {
			cout << "NO" << endl; continue;
		}
		cout << "YES" << endl;
		int sum = 0;
		for (int i = 0; i < n; i ++) {
			sum += a[i];
			if (sum == x) {
				swap(a[i], a[i+1]); break;
			}
		}
		for (int i = 0; i < n; i ++) {
			cout << a[i] << " \n"[i==n-1];
		}
	}
}