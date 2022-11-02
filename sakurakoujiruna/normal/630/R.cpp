#include <iostream>
using namespace std;

typedef long long intl;

int main()
{
	ios :: sync_with_stdio(false);
	intl n;
	cin >> n;
	if(n & 1)
		cout << 1 << '\n';
	else
		cout << 2 << '\n';
	return 0;
}