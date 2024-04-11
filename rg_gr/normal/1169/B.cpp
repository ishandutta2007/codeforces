#include <stdio.h>
#include <string.h> 
#include <queue>
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
int a[300005],b[300005];
#define vis ok
int ok[300005];
signed main()
{
	int n=read(),m=read();
	for(int i=0;i<m;i++)
	{
		a[i]=read(),b[i]=read();
	}
	//solve a[0]
	for(int i=0;i<m;i++)
	{
		if(a[i]==a[0]||b[i]==a[0])ok[i]=1;
	}
	{
		int c=-1;
		for(int i=0;i<m;i++)if(vis[i]==0)
		{
			c=i;
			break;
		}
		if(c==-1)return puts("YES")&0;
		//solve a[c]
		int f=0;
		for(int i=0;i<m;i++)
			if(!vis[i])
			{
				if(a[i]!=a[c]&&b[i]!=a[c])
				{
					f=1;break;
				}
			}
		if(f==0)return puts("YES")&0;
		//solve b[c]
		f=0;
		for(int i=0;i<m;i++)
			if(!vis[i])
			{
				if(a[i]!=b[c]&&b[i]!=b[c])
				{
					f=1;break;
				}
			}
		if(f==0)return puts("YES")&0;
	}
	
	memset(ok,0,sizeof(ok));
	for(int i=0;i<m;i++)
	{
		if(a[i]==b[0]||b[i]==b[0])ok[i]=1;
	}
	{
		int c=-1;
		for(int i=0;i<m;i++)if(vis[i]==0)
		{
			c=i;
			break;
		}
		if(c==-1)return puts("YES")&0;
		//solve a[c]
		int f=0;
		for(int i=0;i<m;i++)
			if(!vis[i])
			{
				if(a[i]!=a[c]&&b[i]!=a[c])
				{
					f=1;break;
				}
			}
		if(f==0)return puts("YES")&0;
		//solve b[c]
		f=0;
		for(int i=0;i<m;i++)
			if(!vis[i])
			{
				if(a[i]!=b[c]&&b[i]!=b[c])
				{
					f=1;break;
				}
			}
		if(f==0)return puts("YES")&0;
	}
	puts("NO");
}