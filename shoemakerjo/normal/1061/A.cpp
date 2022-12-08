#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, S;
	cin >> n >> S;
	// cout << S/n;
	int ans = S/n;
	if (S%n != 0) ans++;
	cout << ans << endl;
}