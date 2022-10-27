#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;
		string s = "";
		int cur = n%3==1?1:2;
		while (n) {
			s += ('0' + cur); n -= cur;
			cur = 3 - cur;
		} 
		cout << s << "\n";
	}
}