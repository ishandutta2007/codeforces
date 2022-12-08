#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define pii pair<int, int>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	int a, b, c, d;
	while (t--) {
		cin >> a >> b >> c >> d;
		cout << max(a+b, c+d) << endl;
	}

}