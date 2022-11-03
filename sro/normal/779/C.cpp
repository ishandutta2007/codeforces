#include <cstdio>
#include <iostream>
#include <algorithm>
#define x first
#define y second
#define mp make_pair
using namespace std;

pair<int,int> cost[234567],jaj[234567];
int n,m,food=0,cnt;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&cost[i].x);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&cost[i].y);
		if(cost[i].x<cost[i].y)food++;
		jaj[i]=mp(cost[i].x-cost[i].y,i);
	}
	sort(jaj,jaj+n);
	if(food<m)
	{
		int i;
		for(i=0;i<m;i++)cnt+=cost[jaj[i].y].x;
		for(   ;i<n;i++)cnt+=cost[jaj[i].y].y;
	}
	else
	{
		int i;
		for(i=0;i<food;i++)cnt+=cost[jaj[i].y].x;
		for(   ;i<n;i++)cnt+=cost[jaj[i].y].y;
	}
	printf("%d",cnt);
	return 0;
}