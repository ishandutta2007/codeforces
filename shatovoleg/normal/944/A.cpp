#pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define len(v) ((int)v.size())
#define pb push_back

typedef long long ll;
typedef long double ld;

int main()
{
	int n, a, b;
	cin >> n >> a >> b;
	--a, --b;
	int amnt = 1;
	for (; (1 << amnt) < n; ++amnt);
	a ^= b;
	int k = -1;
	for (int i = 0; i < 30; ++i)
		if (a & (1 << i))
			k = i;
	++k;
	if (k == amnt)
		cout << "Final!" << endl;
	else
		cout << k << endl;
}