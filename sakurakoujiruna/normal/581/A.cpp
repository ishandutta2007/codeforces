#include <iostream>
using namespace std;

int main()
{
	ios :: sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	int ans1 = min(a, b);
	int ans2 = (max(a, b) - min(a, b)) / 2;
	cout << ans1 << ' ' << ans2 << '\n';

	return 0;
}