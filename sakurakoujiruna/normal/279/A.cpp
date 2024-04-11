#include <iostream>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
	ios :: sync_with_stdio(false);
	int gx, gy;
	cin >> gx >> gy;
	int ans = 0;
	int x = 0, y = 0;
	for(int t = 0; ; t ++)
	{
		int step = t / 2 + 1;
		int nx = x + dx[t % 4] * step;
		int ny = y + dy[t % 4] * step;
		if(min(x, nx) <= gx && gx <= max(x, nx) &&
			min(y, ny) <= gy && gy <= max(y, ny))
			break;
		x = nx;
		y = ny;
		ans ++;
	}
	cout << ans << '\n';
	return 0;
}