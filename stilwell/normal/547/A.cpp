#include <stdio.h>
#include <stdlib.h>
using namespace std;

long long n,i,h1,h2,a1,a2,x1,x2,y1,y2;
int st1[1000005],app1[1000005],top1,l1,len1;
int st2[1000005],app2[1000005],top2,l2,len2;

void work(int h,int x,int y,int *st,int *app,int &top,int &l,int &len)
{
	for(;!app[h];h=((long long)h*x+y)%n)
	{
		st[++top]=h;
		app[h]=top;
	}
	l=app[h];
	len=top-l+1;
}

int main()
{
	scanf("%I64d",&n);
	scanf("%I64d%I64d",&h1,&a1);
	scanf("%I64d%I64d",&x1,&y1);
	scanf("%I64d%I64d",&h2,&a2);
	scanf("%I64d%I64d",&x2,&y2);
	work(h1,x1,y1,st1,app1,top1,l1,len1);
	work(h2,x2,y2,st2,app2,top2,l2,len2);
	if(!app1[a1]||!app2[a2])
	{
		printf("-1\n");
		return 0;
	}
	if(app1[a1]<l1)
	{
		if(app2[a2]<l2)
		{
			if(app1[a1]==app2[a2])printf("%d\n",app1[a1]-1);
			else printf("-1\n");
		}
		else
		{
			if(app1[a1]>=app2[a2]&&(app1[a1]-app2[a2])%len2==0)printf("%d\n",app1[a1]-1);
			else printf("-1\n");
		}
		return 0;
	}
	else
	{
		if(app2[a2]<l2)
		{
			if(app2[a2]>=app1[a1]&&(app2[a2]-app1[a1])%len1==0)printf("%d\n",app2[a2]-1);
			else printf("-1\n");
		}
		else
		{
			if(len1>len2)
			{
				x1=app1[a1];y1=len1;
				x2=app2[a2];y2=len2;
			}
			else
			{
				x1=app2[a2];y1=len2;
				x2=app1[a1];y2=len1;
			}
			for(i=0;i<=1000000;++i)
			{
				if(x1>=x2&&(x1-x2)%y2==0)break;
				x1+=y1;
			}
			if(i<=1000000)printf("%I64d\n",x1-1);
			else printf("-1\n");
		}
		return 0;
	}
}