#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int,int> 
using namespace std;
int n,snk[123456];
pii sth[123456];
bool fanxiang(pii a,pii b)
{return a>b;}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&sth[i].first);
		sth[i].second=i;
		snk[i]=sth[i].first;
	}
	int lastpos=1,start=0;
	sort(sth,sth+n,fanxiang);
	for(int i=0;i<n;i++)
	{
		if(sth[i].second>=lastpos)
		{
			for(int j=lastpos;j<=sth[i].second;j++)puts("");
			lastpos=sth[i].second+1;
		}
		else if(start)printf(" ");if(!start)start=1;
		printf("%d",sth[i].first);
	}
	return 0;
}