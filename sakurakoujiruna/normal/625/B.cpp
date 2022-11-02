#include <iostream>
using namespace std;

int main()
{
	ios :: sync_with_stdio(false);
	string a, b;
	cin >> a >> b;
	int n = a.size();
	int m = b.size();
	int ans = 0;
	for(int i = 0; i < n - m + 1; i ++)
		if(a.substr(i, m) == b)
		{
			ans ++;
			a[i + m - 1] = '#';
		}
	cout << ans << '\n';
	return 0;
}