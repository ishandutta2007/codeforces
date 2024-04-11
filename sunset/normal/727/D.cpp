#include<bits/stdc++.h>

using namespace std;

const int maxn=100010;

int a[10];

int n,cnt;

int g[maxn];

struct node
{
	int pos,t;
}p[maxn];

bool cmp(node a,node b)
{
	return a.t<b.t;
}

int main()
{
	for(int i=1;i<=6;i++)
		scanf("%d",&a[i]);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		char ch[10]={0};
		scanf("%s",ch);
		if(ch[1]==',')
		{
			if(ch[0]=='S') p[++cnt].t=1,p[cnt].pos=i;
			if(ch[0]=='M') p[++cnt].t=2,p[cnt].pos=i;
			if(ch[0]=='L') p[++cnt].t=3,p[cnt].pos=i;
		}
		else if(ch[2]==',')
		{
			p[++cnt].t=4,p[cnt].pos=i;
		}
		else if(ch[3]==',')
		{
			p[++cnt].t=5,p[cnt].pos=i;
		}
		else
		{
			int t;
			if(ch[0]=='S') t=1;
			else if(ch[0]=='M') t=2;
			else if(ch[0]=='L') t=3;
			else if(ch[1]=='L') t=4;
			else if(ch[2]=='L') t=5;
			else t=6;
			a[t]--;
			g[i]=t;
			if(a[t]<0)
			{
				printf("NO");
				return 0;
			}
		}
	}
	sort(p+1,p+cnt+1,cmp);
	//for(int i=1;i<=cnt;i++)
	//	printf("%d %d\n",p[i].t,p[i].pos);
	for(int i=1;i<=cnt;i++)
	{
		if(a[p[i].t])
		{
			a[p[i].t]--;
			g[p[i].pos]=p[i].t;
		}
		else if(a[p[i].t+1])
		{
			a[p[i].t+1]--;
			g[p[i].pos]=p[i].t+1;
		}
		else
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES\n");
	for(int i=1;i<=n;i++)
	{
		if(g[i]==1) printf("S\n");
		if(g[i]==2) printf("M\n");
		if(g[i]==3) printf("L\n");
		if(g[i]==4) printf("XL\n");
		if(g[i]==5) printf("XXL\n");
		if(g[i]==6) printf("XXXL\n");
	}
}