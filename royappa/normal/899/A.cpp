#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	int n1 = 0, n2 = 0;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		if (x == 1) n1++; else n2++;
	}
	int res = 0;
	res += min(n1, n2);
	n1 -= min(n1, n2);
	res += n1/3;
	cout << res << endl;
	exit(0);
}