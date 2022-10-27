#include <bits/stdc++.h>
using namespace std;

const int N = 20000 + 10;
int t;
typedef long long ll;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);

	cin >> t;
	while (t --) {
		ll n, s;
		cin >> n >> s;
		cout << s / (n * n) << "\n";
	}
}