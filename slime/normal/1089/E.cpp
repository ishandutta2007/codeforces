#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
void otp(int x, int y)
{
	cout<<char('a' + y - 1)<<x<<" ";
}
int ns[64][2];
int t[9][9];
int main()
{
	ns[0][0] = 1, ns[0][1] = 1;
	for(int i = 1; i < 64; i++)
	{
		if(i <= 48)
		{
			ns[i][0] = i / 8 + 1;
			if((i / 8) & 1)
				ns[i][1] = 8 - i % 8;
			else ns[i][1] = i % 8 + 1;
		}
		else
		{
			if(i <= 59)
			{
				if(i % 2) ns[i][0] = 15 - ns[i - 1][0], ns[i][1] = ns[i - 1][1];
				else ns[i][0] = ns[i - 1][0], ns[i][1] = ns[i - 1][1] + 1;
			}
			else if(i == 60) ns[i][0] = 7, ns[i][1] = 8;
			else if(i == 61) ns[i][0] = 7, ns[i][1] = 7;
			else if(i == 62) ns[i][0] = 8, ns[i][1] = 7;
			else ns[i][0] = 8, ns[i][1] = 8;
		}
		t[ns[i][0]][ns[i][1]] = i;
	}
	int n;
	scanf("%d", &n);
	if(n == 62)
	{
		for(int i = 0; i <= 63; i++)
			if(i != 60)
				otp(ns[i][0], ns[i][1]);
		return 0;
	}
	for(int i = 0; i < n - 1; i++)
		otp(ns[i][0], ns[i][1]);
	for(int i = 1; i <= 8; i++)
		for(int j = 1; j <= 8; j++)
		{
			if(i == 8 && j == 8) continue;
			if(i != 8 && j != 8) continue;
			if(i != ns[n - 2][0] && j != ns[n - 2][1]) continue;
			if(i == ns[n - 2][0] && j == ns[n - 2][1]) continue;
			if(t[i][j] <= n - 2) continue;
			otp(i, j);
			otp(8, 8);
			return 0;
		}
	return 0;
}