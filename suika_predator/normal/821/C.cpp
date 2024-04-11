#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,x,ans,cnt=1;
char buf[50];
int st[300300],top,mark[300300];
int main()
{
	scanf("%d",&n);
	//scanf("%s",buf);
	for(int i=1;i<=2*n;i++)
	{
		scanf("%s",buf);
		if(buf[0]=='a')
		{
			scanf("%d",&x);
			st[++top]=x;
		}
		else
		{
			if(top&&st[top]!=cnt)
			{
				while(top)
					mark[st[top--]]=1;ans++;
				
			}
			else if(top)
				top--;cnt++;
		}
	}
	for(int i=1;i<=n;i++)if(mark[i])cnt++;
	printf("%d\n",ans);
	return 0;
}