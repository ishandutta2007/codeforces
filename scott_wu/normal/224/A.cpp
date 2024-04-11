#include <iostream>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int d, e, f;
	
	d = a * b / c, e = a * c / b, f = b * c / a;
	
	int ans = 0;
	for (int i = 0; i <= 10000; i++)
	{
		if (i * i == d)
			ans += 4 * i;
		if (i * i == e)
			ans += 4 * i;
		if (i * i == f)
			ans += 4 * i;
	}
	
	cout << ans << "\n";
	return 0;
}