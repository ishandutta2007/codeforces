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
		int n, k, kk;
		cin >> n >> k; kk = k;
		int l = 1, r = n;
		vector<int> v;
		while (k) {
			v.push_back(l ++);
			v.push_back(r --);
			k --;
		}
		for (int i = r; i >= l; i --) v.push_back(i);
		int cnt = 0;
		for (int i = 1; i < n - 1; i ++) {
			if (v[i] > v[i-1] && v[i] > v[i+1]) cnt ++;
		}

		if (cnt != kk) cout << -1 << endl;
		else {
			for (auto x: v) cout << x << " ";
			cout << endl;
		}

	}  
}