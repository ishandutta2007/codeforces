#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100005
#define maxs 17
#define ll long long
using namespace std;
int dis[maxs][maxn];
int frs[maxs][maxn];
int act[maxs][maxn][2];
int q[maxn], fr, ed;
int n;
int a[maxn];
int ots[maxn][3], otcnt;
void push(int x, int y)
{
	ots[otcnt][0] = x, ots[otcnt][1] = y, ots[otcnt++][2] = 2 * y - x;
	a[x] ^= 1, a[y] ^= 1, a[2 * y - x] ^= 1;
}
bool flag = 1;
void work(int pl)
{
	if(n - pl + 1 < maxs)
	{
		int id = n - pl + 1;
		int ns = 0;
	//	cout<<a[1]<<" "<<pl<<endl;
		for(int j = pl; j <= n; j++)
			if(a[j])
				ns += (1 << (j - pl));
	//			cout<<"PLS"<<j - pl<<endl;
		if(dis[id][ns] >= maxn)
		{
			printf("NO\n");
			flag = 0;
			return ;
		}
	//	cout<<ns<<endl;
		int nans = ns;
		while(nans)
		{
			push(pl + act[id][nans][0], pl + act[id][nans][1]);
			nans = frs[id][nans];
		}
		return ;
	}
	int sum = a[pl] + a[pl + 1] + a[pl + 2];
	if(sum == 0) work(pl + 3);
	else if(sum == 3)
	{
		push(pl, pl + 1);
		work(pl + 3);
	}
	else if(sum == 1)
	{
		int pls = 0;
		for(int j = 0; j < 3; j++)
			if(a[pl + j]) pls = pl + j;
		push(pls, pl + 3);
		work(pl + 3);
	}
	else
	{
		int pls[2], plcnt = 0;
		for(int j = 0; j < 3; j++)
			if(a[pl + j])
				pls[plcnt++] = pl + j;
		if(pls[1] != pl + 1)	
		{
			push(pls[0], pls[1]);
			work(pl + 3);
		}
		else
		{
			int sm2 = a[pl + 3] + a[pl + 4] + a[pl + 5];
			if(sm2 == 3)
			{
				push(pl + 1, pl + 3);
				push(pl, pl + 4);
			}
			else if(sm2 == 0)
			{
				push(pl, pl + 4), 
				push(pl + 1, pl + 4);
			}
			else if(sm2 == 1)
			{
				int fpl;
				for(int j = 3; j < 6; j++)
					if(a[pl + j]) fpl = pl + j;
				push(pl, fpl);
				push(pl + 1, pl + 6);
			}
			else
			{
				int fpl[2], fcnt = 0;
				for(int j = 3; j < 6; j++)
					if(a[pl + j]) fpl[fcnt++] = pl + j;
				push(pl, fpl[0]), 
				push(pl + 1, fpl[1]);
			}
			work(pl + 6);
		}
	}
}
int main()
{
	for(int i = 3; i < maxs; i++)
	{
		for(int j = 0; j < (1 << i); j++)
			dis[i][j] = maxn;
		dis[i][0] = 0;
		fr = ed = 0;
		q[ed++] = 0;
	//	cout<<i<<" "<<(1 << i)<<endl;
		while(fr < ed)
		{
			for(int x = 0; x < i; x++)
				for(int y = x + 1; y * 2 - x < i; y++)
				{
					int eds = q[fr] ^ (1 << x) ^ (1 << y) ^ (1 << (y * 2 - x));
					if(dis[i][eds] > dis[i][q[fr]] + 1)
					{
						dis[i][eds] = dis[i][q[fr]] + 1, 
						frs[i][eds] = q[fr];
						act[i][eds][0] = x, act[i][eds][1] = y;
						q[ed++] = eds;
					}
				//	cout<<eds<<endl;
				}
			fr++;
		}
		int mxs = 0;
		for(int k = 0; k < (1 << i); k++)
			mxs = max(mxs, dis[i][k]);
	//	cout<<i<<" "<<mxs<<endl;
	}
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	work(1);
	if(flag)
	{
		printf("YES\n");
		printf("%d\n", otcnt);
		for(int i = 0; i < otcnt; i++)
			printf("%d %d %d\n", ots[i][0], ots[i][1], ots[i][2]);
	}
	return 0;
}