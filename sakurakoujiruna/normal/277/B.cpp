#include <iostream>
using namespace std;

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	if(m == 3 && n > 4)
		cout << -1 << '\n';
	else if(m == 3 && n == 4)
		cout << "1 0\n-1 0\n0 1\n0 2\n";
	else
	{
		for(int i = 1; i <= m; i ++)
			cout << i << ' ' << 2 * i * i << '\n';
		for(int i = 1; i <= n - m; i ++)
			cout << i << ' ' << -2 * i * i - 1 << '\n';
	}
	return 0;
}