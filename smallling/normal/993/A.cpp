#include <bits/stdc++.h>

using namespace std;

struct point{
	int x, y;
}a[10], b[10];

int flag[420][420];

int main()
{
	int xl = 110, xr = -110, yl = 110, yr = -110;
	for(int i = 1; i <= 4; i++)
	{
		scanf("%d%d", &a[i].x, &a[i].y);
		xl = min(xl, a[i].x);
		xr = max(xr, a[i].x);
		yl = min(yl, a[i].y);
		yr = max(yr, a[i].y);
	}
	for(int i = xl; i <= xr; i++)
		for(int j = yl; j <= yr; j++)
			flag[i + j + 200][i - j + 200] = 1;
	for(int i = 1; i <= 4; i++)
	{
		scanf("%d%d", &b[i].x, &b[i].y);
	}
	for(int i = 1; i <= 4; i++)
	{
		int x = a[i].x, y = a[i].y;
		a[i].x = x + y, a[i].y = x - y;
		x = b[i].x, y = b[i].y;
		b[i].x = x + y, b[i].y = x - y;
	}
	xl = 310, xr = -310, yl = 310, yr = -310;
	for(int i = 1; i <= 4; i++)
	{
		xl = min(xl, b[i].x);
		xr = max(xr, b[i].x);
		yl = min(yl, b[i].y);
		yr = max(yr, b[i].y);
	}
	for(int i = xl; i <= xr; i++)
		for(int j = yl; j <= yr; j++)
			if(flag[i + 200][j + 200])return puts("YES"), 0;
	
	puts("NO");
}