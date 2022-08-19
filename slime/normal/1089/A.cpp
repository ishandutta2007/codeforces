#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct th
{
	int x, y;
	int t[5];
	th()
	{
		x = -100, y = 100;
	}
	void otp()
	{
		if(x < 0)
			printf("Impossible\n");
		else
		{
			printf("%d:%d\n", x, y);
			for(int i = 0; i < x + y; i++)
				printf("%d:%d ", t[i] / 500, t[i] % 500);
			printf("\n");
		}
	}
	bool operator < (th z)
	{
		return x - y < z.x - z.y;
	}
};
th ans[205][205][5][5];
th mx(th a, th b)
{
	if(a < b) return b;
	return a;
}
th gt(int k, int l, int i, int j, int x, int y)
{
	th n1;
	if(k < x || l < y) return n1;
	int ei = i, ej = j;
	if(x > y) ei++;
	else ej++;
	n1 = ans[k - x][l - y][ei][ej];
	n1.t[i + j] = x * 500 + y;
	return n1;
}
int main()
{
	for(int i = 3; i >= 0; i--)
		for(int j = 3; j >= 0; j--)
		{
			if(i + j > 5) continue;
			for(int k = 0; k < 205; k++)
				for(int l = 0; l < 205; l++)
				{
					if(i >= 3 || j >= 3)
					{
						if(!k && !l) ans[k][l][i][j].x = i, ans[k][l][i][j].y = j;
					}
					else
					{
						int s = 25;
						if(i + j == 4) s = 15;
						for(int t = 0; t < s - 1; t++)
							ans[k][l][i][j] = mx(ans[k][l][i][j], gt(k, l, i, j, t, s)), 
							ans[k][l][i][j] = mx(ans[k][l][i][j], gt(k, l, i, j, s, t));
						for(int t = s + 1; 2 * t - 2 <= k + l; t++)
							ans[k][l][i][j] = mx(ans[k][l][i][j], gt(k, l, i, j, t, t - 2)), 
							ans[k][l][i][j] = mx(ans[k][l][i][j], gt(k, l, i, j, t - 2, t));
					}				
				}
		}
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		ans[a][b][0][0].otp();
	}
	return 0;
}