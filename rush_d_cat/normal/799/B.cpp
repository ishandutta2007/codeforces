#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<set>
using namespace std;
#define ll long long
#define mp make_pair
#define X first
#define Y second
const int N=200008;
const int M=2000000000;
set<int>d[9];
int n,m,a[N],b[N],c[N];
int main(void)
{
	int i,k,p1,p2;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++)scanf("%d",b+i);
	for(i=1;i<=n;i++)scanf("%d",c+i);
	for(i=1;i<=n;i++)d[(b[i]-1)*3+c[i]-1].insert(a[i]);
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		p1=M;p2=-1;
		scanf("%d",&k);
		if(!d[(k-1)*3+0].empty()&&*d[(k-1)*3+0].begin()<p1){p1=*d[(k-1)*3+0].begin();p2=(k-1)*3+0;}
		if(!d[(k-1)*3+1].empty()&&*d[(k-1)*3+1].begin()<p1){p1=*d[(k-1)*3+1].begin();p2=(k-1)*3+1;}
		if(!d[(k-1)*3+2].empty()&&*d[(k-1)*3+2].begin()<p1){p1=*d[(k-1)*3+2].begin();p2=(k-1)*3+2;}
		if(!d[0+k-1].empty()&&*d[0+k-1].begin()<p1){p1=*d[0+k-1].begin();p2=0+k-1;}
		if(!d[3+k-1].empty()&&*d[3+k-1].begin()<p1){p1=*d[3+k-1].begin();p2=3+k-1;}
		if(!d[6+k-1].empty()&&*d[6+k-1].begin()<p1){p1=*d[6+k-1].begin();p2=6+k-1;}
		if(p1==M)printf("-1 ");
		else {printf("%d ",p1);d[p2].erase(d[p2].begin());}
	}
	return 0;
}