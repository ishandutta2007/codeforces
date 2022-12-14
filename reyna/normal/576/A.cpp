//In the name of God
#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
int main() {
	int n; cin >> n;
	int cnt = 0;
	for (int i = 2; i <= n; ++i) {
		int k = 0, x = i;
		for (int j = 2; j <= i; ++j) {
			if (x % j == 0) ++k;
			while (x % j == 0) x /= j;
		}
		if (k == 1)
			ans.push_back(i), ++cnt;
	}
	cout << cnt << endl;
	for (auto x : ans)
		cout << x << ' ';
}