#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i < n * m; ++i)
	{
		int x; cin >> x;
		int y; cin >> y;
		cnt += x | y;
	}
	cout << cnt << endl;
	return 0;
}