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
		int n;
		cin >> n;
		vector<int> a(n);
		int s = -1;
		for (int i = 0; i < n; i ++) {
			cin >> a[i]; 
			if (s == -1) s = a[i];
			s &= a[i];
		}
		cout << s << endl;
	}
}