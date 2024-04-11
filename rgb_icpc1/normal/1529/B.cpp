#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
int a[N];

int main() {
	int T; cin >> T;
	while (T --) {
		int n; cin >> n;
		vector<int> v;
		for (int i = 0; i < n; i ++) {
			cin >> a[i];
			if (a[i] <= 0) v.push_back(a[i]);
		}
		sort(v.begin(), v.end());
		int mx = INT_MAX;
		for (int i = 0; i < (int)v.size() - 1; i ++) mx = min(mx, abs(v[i + 1] - v[i]));
		int rlt = 0, one = 0, mn = INT_MAX;
		for (int i = 0; i < n; i ++) {
			if (a[i] <= 0) rlt ++;
			else {
				one ++;
				mn = min(mn, a[i]);
			}
		}
		if (one && mn <= mx) rlt ++;
		cout << rlt << endl;
	}
}