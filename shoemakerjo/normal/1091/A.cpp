#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int y, b, r;
	cin >> y >> b >> r;
	int st = r-2;
	st = min(st, b-1);
	st = min(st, y);

	if (st < 0) cout << 0 << endl;
	else cout << 3*st + 3 << endl;
}