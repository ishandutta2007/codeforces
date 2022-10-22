#include <bits/stdc++.h>

using namespace std;
typedef long long nagai;

int main()
{
	nagai n, m;
	cin >> n >> m;
	if (n >= 30)
		cout << m << endl;
	else
		cout << m % (1 << n) << endl;
	return 0;
}