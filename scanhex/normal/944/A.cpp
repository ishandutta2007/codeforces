#include <bits/stdc++.h>

using namespace std;
typedef long long nagai;
typedef long double db;
typedef complex<db> cp;


int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int a, b;
	cin >> a >> b;
	--a, --b;
	for (int i = 0; i < 9; ++i)
		if ((a >> i) == ((b >> i) ^ 1))
		{
			if ((1 << i + 1) == n)
				cout << "Final!\n";
			else
				cout << i + 1 << '\n';
			return 0;
		}
}