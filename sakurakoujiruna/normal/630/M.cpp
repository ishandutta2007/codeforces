#include <iostream>
using namespace std;

typedef long long intl;

int main()
{
	intl n;
	cin >> n;
	n %= 360;
	n = (n + 360) % 360;
	if(n <= 45 || n >= 315)
		cout << 0 << '\n';
	else if(n > 45 && n <= 135)
		cout << 1 << '\n';
	else if(n > 135 && n <= 225)
		cout << 2 << '\n';
	else
		cout << 3 << '\n';
	return 0;
}