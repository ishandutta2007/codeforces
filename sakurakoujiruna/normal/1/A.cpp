#include <bits/stdc++.h>
using namespace std;

typedef long long intl;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	a = (a + c - 1) / c;
	b = (b + c - 1) / c;
	cout << (intl)a * b << '\n';
	return 0;
}