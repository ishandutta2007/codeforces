#include <stdio.h>
#include <string.h> 
#include <queue>
#include <algorithm>
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
int cmp(int a,int b)
{
	return a>b;
}
int a[200005];
int b[200005],c[200005];
int bb,cc;
#define continue goto ng
signed main()
{
    int T=read();
	while(T--)
	{
		int n=read(),ans=0;bb=cc=0;
		for(int i=0;i<n;i++)a[i]=read();
		for(int i=0;i<n;i++)
		{
			if(a[i]&1)c[cc++]=a[i];
			else b[bb++]=a[i];
		}
		std::sort(b,b+bb);
		std::sort(c,c+cc);
		int p=0,A=0,B=0;
		while(p<n)
		{
			p++;
			if(p&1)
			{
				if(bb==0)
				{
					cc--;
					continue;
				}
				if(cc==0)
				{
					B+=b[--bb];
					continue;
				}
				int x=b[bb-1],y=c[cc-1];
				if(x>y)B+=b[--bb];
				else cc--;
			}
			else
			{

				if(cc==0)
				{
					bb--;
					continue;
				}
				if(bb==0)
				{
					A+=c[--cc];
					continue;
				}
				int x=b[bb-1],y=c[cc-1];
				if(x<y)A+=c[--cc];
				else bb--;
			}
			ng:;
			//printf("%lld %lld\n",bb,cc);
		}
		if(A>B)puts("Bob");
		else if(A==B)puts("Tie");
		else puts("Alice");
	}
}