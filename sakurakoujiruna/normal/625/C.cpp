#include <iostream>
using namespace std;

const int N = 511;

int num[N][N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, k;
	cin >> n >> k;

	int nid = 1;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j < k; j ++)
			num[i][j] = nid ++;
	for(int i = 1; i <= n; i ++)
		for(int j = k; j <= n; j ++)
			num[i][j] = nid ++;

	int ans = 0;
	for(int i = 1; i <= n; i ++)
		ans += num[i][k];

	cout << ans << '\n';
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= n; j ++)
			cout << num[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}