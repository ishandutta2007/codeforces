#include <iostream>
using namespace std;

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	int ans = 1;
	for(int i = 0; i < n; i ++)
	{
		int x;
		cin >> x;
		if(x == 1)
			ans = -1;
	}
	cout << ans << '\n';
	return 0;
}