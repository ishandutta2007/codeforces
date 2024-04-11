#include <iostream>
using namespace std;

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int c2 = 0, c3 = 0, cc = 0;
	for(int i = 1; i <= 3 * (n + m) + 5; i ++)
	{
		if(i % 2 == 0 && i % 3 == 0)
			cc ++;
		else if(i % 2 == 0)
			c2 ++;
		else if(i % 3 == 0)
			c3 ++;

		int need2 = max(0, n - c2);
		int need3 = max(0, m - c3);
		if(need2 + need3 <= cc)
		{
			cout << i << '\n';
			break;
		}
	}
	return 0;
}