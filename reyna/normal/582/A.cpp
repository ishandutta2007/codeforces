//In the name of God
#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
const int N = 500 * 500 + 500;
int a[N];
vector <int> v;
vector <int> ans;
int main() {
	ios_base::sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 0; i < n * n; ++i) {
		int x; cin >> x;
		a[i] = x;
	}
	sort(a, a + n * n);
	reverse(a, a + n * n);
	n = n * n;
	for (int i = 0; i < n; ++i) {
		int x = a[i];
		if (mp[x]) {
			mp[x]--;
			continue;	
		}
		for (int j = 0; j < ans.size(); ++j)
			mp[__gcd(ans[j], x)] += 2;
		ans.push_back(x);
	}
	for (auto x: ans)
		cout << x << ' ';
	return 0;
}