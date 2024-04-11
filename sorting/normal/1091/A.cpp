#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int y, b, r;

	cin >> y >> b >> r;

	int mx_r = min(r, min(b+1, y+2) );

	cout << 3*mx_r - 3 << "\n";

	return 0;
}