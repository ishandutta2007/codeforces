#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n,bvl,id;
int a[N];
void Solve()
{
	int i,c0,c1;
	scanf("%d",&n);
	bvl=0;
	for(i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		bvl^=a[i];
	}
	if(bvl==0)
	{
		puts("DRAW");
		return ;
	}
	id=30;
	while((bvl&(1<<id))==0) id--;
	c0=c1=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]&(1<<id)) c1++;
		else c0^=1;
	}
	if(c0==0)
	{
		if(c1%4==1) puts("WIN");
		else puts("LOSE");
	}
	else
	{
		puts("WIN");
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--) Solve();
	return 0;
}