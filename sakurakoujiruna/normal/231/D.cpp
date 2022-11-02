#include <iostream>
using namespace std;

int a[8];

int main()
{
	ios :: sync_with_stdio(false);
	int x, y, z;
	cin >> x >> y >> z;
	int bx, by, bz;
	cin >> bx >> by >> bz;
	for(int i = 1; i <= 6; i ++)
		cin >> a[i];

	int ans = 0;
	if(y < 0) ans += a[1];
	if(y > by) ans += a[2];
	if(z < 0) ans += a[3];
	if(z > bz) ans += a[4];
	if(x < 0) ans += a[5];
	if(x > bx) ans += a[6];

	cout << ans << '\n';
	return 0;
}