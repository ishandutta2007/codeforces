#include<bits/stdc++.h>
using namespace std;
const int N=510;
int n,m,hcn=0,lcn=0,hid,hst,hen,lid,lst,len,vtag,pd,js,pos,x;
char t[N][N];
int main()
{
//	freopen("b.in","r",stdin);
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%s",t[i]+1);
	}
	pos=0;
	for(i=1;i<=n;i++)
	{
		vtag=0;js=0;
		for(j=1;j<=m;j++)
		{
			if(t[i][j]=='*') 
			{
				js++;x=j;
				if(vtag==2)
				{
					puts("NO");return 0;
				}
				vtag=1;
			}
			else if(t[i][j]=='.'&&vtag==1) vtag=2;
		}
		if(js==1)
		{
			if(pos>0&&x!=pos) 
			{
				puts("NO");return 0;
			}
			pos=x;
		}
		if(js>1)
		{
			hcn++;
			hid=i;
			for(j=1;j<=m;j++)
			{
				if(t[i][j]=='*') 
				{
					hst=j;break;
				}
			}
			for(j=m;j>=1;j--)
			{
				if(t[i][j]=='*') 
				{
					hen=j;break;
				}
			}
		}
	}
	pos=0;
	for(j=1;j<=m;j++)
	{
		vtag=0;js=0;
		for(i=1;i<=n;i++)
		{
			if(t[i][j]=='*')
			{
				x=pos;
				js++;
				if(vtag==2)
				{
					puts("NO");return 0;
				}
				vtag=1;
			}
			else if(t[i][j]=='.'&&vtag==1) vtag=2;
		}
		if(js==1)
		{
			if(pos>0&&x!=pos) 
			{
				puts("NO");return 0;
			}
			pos=x;
		}
		if(js>1)
		{
			lcn++;
			lid=j;
			for(i=1;i<=n;i++) 
			{
				if(t[i][j]=='*') 
				{
					lst=i;break;
				}
			}
			for(i=n;i>=1;i--)
			{
				if(t[i][j]=='*')
				{
					len=i;break;
				}
			}
		}
	}
	//puts("OK");
	//printf("%d %d\n",hcn,lcn);
	if(hcn!=1||lcn!=1) 
	{
		puts("NO");return 0;
	}
	if(hid>lst&&hid<len&&lid>hst&&lid<hen) puts("YES");
	else puts("NO");
	return 0;
}