#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100005
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
int x[4], y[4]; 
int ds[3];
int cal(int a, int b)
{
	int ans = abs(x[a] - x[b]) + abs(y[a] - y[b]);
	return ans;
}
bool fl[1005][1005];
void otp(int i)
{
	int nx = x[3], ny = y[3];
	while(1)
	{
		if(nx < x[i]) nx++;
		else if(nx > x[i]) nx--;
		else if(ny < y[i]) ny++;
		else if(ny > y[i]) ny--;
		if(!fl[nx][ny])
			printf("%d %d\n", nx, ny);	
		fl[nx][ny] = 1;
		if(nx == x[i] && ny == y[i]) return ;
	}
}
int main()
{
	for(int i = 0; i < 3; i++)
		scanf("%d%d", &x[i], &y[i]);
	int mns = maxn * 100;
	int nj = 0, nk = 0;
	for(int j = 0; j <= 1000; j++)
		for(int k = 0; k <= 1000; k++)
		{
			x[3] = j, y[3] = k;
			int nans = 0;
			for(int i = 0; i < 3; i++)
				nans += cal(i, 3);
			if(nans < mns)
				mns = nans, nj = j, nk = k;
		}
	printf("%d\n", mns + 1);
	x[3] = nj, y[3] = nk;
	for(int i = 0; i < 3; i++)
		otp(i);
	if(!fl[x[3]][y[3]])
		printf("%d %d\n", x[3], y[3]);
	return 0;
}