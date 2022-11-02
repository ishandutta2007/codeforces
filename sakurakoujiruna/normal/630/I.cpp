#include <iostream>
using namespace std;

typedef long long intl;

int main()
{
	int n;
	cin >> n;
	if(n == 3)
	{
		cout << 24 << '\n';
		return 0;
	}
	intl pow4 = 1;
	for(int i = 0; i < n * 2 - 2 - n - 2; i ++)
		pow4 *= 4;
	intl ans = 0;
	//cout << pow4 << '\n';
	ans += 4 * 2 * pow4 * 4 * 3;
	ans += 4 * (n - 3) * pow4 * 3 * 3;
	cout << ans << '\n';
	return 0;
}