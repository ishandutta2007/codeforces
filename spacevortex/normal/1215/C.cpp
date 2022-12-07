#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
int n,tot=0;
int p1=0,p2=0;
char a[N],b[N];
int qx[N],qy[N];
void put(int x,int y)
{
	tot++;qx[tot]=x;qy[tot]=y;
}
int main()
{
	int i;
	scanf("%d",&n);
	scanf("%s",a+1);
	scanf("%s",b+1);
	for(i=1;i<=n;i++)
	{
		if(a[i]==b[i]) continue;
		if(a[i]=='b') 
		{
			if(p1) put(p1,i),p1=0;
			else p1=i;
		}
		else
		{
			if(p2) put(p2,i),p2=0;
			else p2=i;
		}
	}
	if(p1>0&&p2>0)
	{
		put(p1,p1);put(p1,p2);
		p1=p2=0;
	}
	if(p1||p2) puts("-1");
	else
	{
		printf("%d\n",tot);
		for(i=1;i<=tot;i++)
		{
			printf("%d %d\n",qx[i],qy[i]);
		}
	}
	return 0;
}