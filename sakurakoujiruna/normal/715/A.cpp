#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	cout << "2\n";
	for(ll i = 2; i <= n; i ++)
		cout << i * (i + 1) * (i + 1) - (i - 1) << '\n';
	return 0;
}