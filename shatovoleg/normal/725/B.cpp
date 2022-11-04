#include <iostream>
#include <string>

using namespace std;

typedef unsigned long long ll;

int main()
{
	ll n;
	char c;
	cin >> n >> c;
	--n;
	ll num = n / 4;
	ll res = 0;
	res += num * 16;
	n %= 4;
	if (n == 1 || n == 3)
		res += 7;
	if (c == 'f')
		res += 1;
	if (c == 'e')
		res += 2;
	if (c == 'd')
		res += 3;
	if (c == 'a')
		res += 4;
	if (c == 'b')
		res += 5;
	if (c == 'c')
		res += 6;
	cout << res << endl;
}