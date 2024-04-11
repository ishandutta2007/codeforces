#include <stdio.h>
#include <string.h> 
#include <queue>
#include <algorithm>
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
int a[300005];
int suf[30][300005],cnt[30];
std::queue<int> q;
signed main()
{
	int n=read(),qq=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1,p=0;i<=300000;p++,i<<=1)
	{
		for(int j=1;j<=n;j++)
			if(a[j]&i)suf[p][cnt[p]++]=j;
	}
	while(qq--)
	{
		//f//or(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
		int x=read(),y=read();
		while(!q.empty())q.pop();
		if(a[x]&a[y]){puts("Shi");continue;}
		if(a[x]==0||a[y]==0){puts("Fou");continue;}
		q.push(x);
		while(!q.empty())
		{	
			int u=q.front();q.pop();
			//p//rintf("u = %d\n",u);
			if(a[u]&a[y]){/*printf("%d\n",u);*/puts("Shi");goto ng;}
			for(int i=1,p=0;i<=300000;p++,i<<=1)
			{
				if(a[u]&i)
				{
					int cur=u;
					tle:;
					int xx=std::upper_bound(suf[p],suf[p]+cnt[p],cur)-suf[p];
					xx=suf[p][xx];
					//printf("xx = %d\n",xx);
					if(xx<=y)
					{
						if(a[xx]&a[y]){/*printf("%d\n",xx);*/puts("Shi");goto ng;}
						if((a[xx]|a[u])==a[u]){cur=xx;goto tle;}
						q.push(xx);
					}
				}
			}
		}
		puts("Fou");
		ng:;
	}
}