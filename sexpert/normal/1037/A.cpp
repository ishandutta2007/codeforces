#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, ans = 0;
	cin >> n;
	long long x = 1;
	while(x <= n)
	{
		x <<= 1ll;
		ans++;
	}
	cout << ans << "\n";
	return 0;
}