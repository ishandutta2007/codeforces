#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<functional>
#include<numeric>
#include<array>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<deque>
#include<list>
#include<iomanip>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto& t : a)
			cin >> t;
		int lptr = 0;
		while (lptr < n && a[lptr] == lptr + 1)
			lptr++;
		int rptr = n - 1;
		while (rptr > 0 && a[rptr] == rptr + 1)
			rptr--;
		bool ok = 1;
		for (int i = lptr; i < rptr; i++)
			ok &= a[i] != i + 1;
		if (lptr == n)
			cout << "0\n";
		else {
			if (ok)
				cout << "1\n";
			else
				cout << "2\n";
		}
	}
	return 0;
}