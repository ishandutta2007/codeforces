#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
	int n; cin >> n;
	vector<int64> b(n);
	int64 ans = 0;
	int64 curp = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> b[i];
		ans += abs(b[i] - curp);
		curp += b[i] - curp;
	}
	cout << ans << endl;
}