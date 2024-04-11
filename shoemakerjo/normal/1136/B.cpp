#include <bits/stdc++.h>

using namespace std;

int n, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;

	int res = min(n - 1 + k-1, n - 1 + n-k);
	res += n;
	res += n+1;
	cout << res << endl;
}