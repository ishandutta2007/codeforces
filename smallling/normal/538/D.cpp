#include<cstdio>

using namespace std;

struct lhy{
	int x,y;
}li[100010],yo[100010],ans[100010];

char Ans[1010][1010],a[1010][1010];
int n,nowx,nowy,x,y,bo,yocnt,licnt,tot,flag[1010][1010];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]=='x')
				yo[++yocnt]=(lhy){i,j};
			if(a[i][j]=='o')
				li[++licnt]=(lhy){i,j};
		}
	for(int i=1;i<=yocnt;i++)
		if(!flag[yo[i].x][yo[i].y])
		{
			bo=0;
			for(int j=1;j<=licnt;j++)
			{
				x=yo[i].x-li[j].x;
				y=yo[i].y-li[j].y;
				bo=1;
				for(int k=1;k<=licnt;k++)
					if(k^j)
					{
						nowx=li[k].x+x;
						nowy=li[k].y+y;
						if(nowx<=0||nowx>n||nowy<=0||nowy>n)continue;
						if(a[nowx][nowy]=='.')
						{
							bo=0;
							break;
						}
					}
				if(bo)
				{
					ans[++tot]=(lhy){x,y};
					for(int k=1;k<=licnt;k++)
					{
						nowx=li[k].x+x;
						nowy=li[k].y+y;
						if(nowx<=0||nowx>n||nowy<=0||nowy>n)continue;
						flag[nowx][nowy]=1;
					}
					break;
				}
			}
			if(!bo)return puts("NO"),0;
		}
	for(int i=1;i<=2*n-1;i++)
		for(int j=1;j<=2*n-1;j++)Ans[i][j]='.';
	for(int i=1;i<=tot;i++)Ans[n+ans[i].x][n+ans[i].y]='x';
	Ans[n][n]='o';
	puts("YES");
	for(int i=1;i<=2*n-1;i++)
	{
		for(int j=1;j<=2*n-1;j++)putchar(Ans[i][j]);
		putchar('\n');
	}
}