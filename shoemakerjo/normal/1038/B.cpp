#include <bits/stdc++.h>

using namespace std;

#define ll long long
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	if (n <= 2) {
		cout << "No" << endl;
		return 0;
	}
	ll sum = (n*(n+1LL))/2LL;
	for (ll div = 2LL; div <= n; div+=1LL) {
		if (sum%div == 0) {
			cout << "Yes" << endl;
			cout << 1 << " " << div << endl;
			cout << n-1;
			for (ll i = 1LL; i <= n; i++) {
				if (i != div) cout << " " << i;
			}
			cout << endl;
			return 0;
		}
	}
	cout << "No" << endl;
}