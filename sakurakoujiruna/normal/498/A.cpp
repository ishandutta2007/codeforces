#include <iostream>
using namespace std;

typedef long long intl;
int sgn(intl n)
{
	return (n > 0) - (n < 0);
}

int main()
{
	ios :: sync_with_stdio(false);
	intl x1, y1;
	intl x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 0; i < n; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		intl d1 = a * x1 + b * y1 + c;
		intl d2 = a * x2 + b * y2 + c;
		ans += (sgn(d1) * sgn(d2) == -1);
	}
	cout << ans << '\n';
	return 0;
}