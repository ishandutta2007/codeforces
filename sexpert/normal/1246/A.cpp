#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, p;
	cin >> n >> p;
	for(int k = 0; k < 40; k++) {
		if(n - k * p < k)
			continue;
		if(__builtin_popcount(n - k * p) <= k) {
			cout << k << '\n';
			return 0;
		}
	}
	cout << "-1\n";
}