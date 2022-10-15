#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int x,hh,mm;
int a[MAXN];
bool check(int x,int y)
{
	if(x%10==7||x/10==7||y%10==7||y/10==7) return true;
	return false;
}
int main()
{
	scanf("%d%d%d",&x,&hh,&mm);
	int cnt=0;
	while(!check(hh,mm)||cnt%x!=0)
	{
		mm--;
		if(mm<0) {hh--; mm+=60;}
		if(hh<0) hh+=24;
		cnt++;
	}
	printf("%d\n",cnt/x);
	return 0;
}