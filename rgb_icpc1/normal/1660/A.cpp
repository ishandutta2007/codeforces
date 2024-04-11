#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long LL;
typedef pair<int, int> pii;

const int MX = 1000005;
const int MOD = 1000000007;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		int a,b ;
		cin >> a >> b;
		if (!a) cout << 1 << endl;
		else cout << a + b * 2 + 1 << endl;
	}

	return 0;
}