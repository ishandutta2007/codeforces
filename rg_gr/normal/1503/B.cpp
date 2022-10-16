#include <stdio.h>
#include <string.h>
#include <algorithm>
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>=48&&c<=57)num=num*10+(c^48),c=getchar();
	return num*f-1;
}
inline int re1d()
{
	char c=getchar();
	while(c<'a'||c>'z'){c=getchar();}
	return c-97;
}
//aabaa
int a[105][105];
int cmp(int aa,int ab)
{
	return a[aa]>a[ab];
}
#define cur0 cnt0
#define cur1 cnt1
int c[300005];
void query(int b,int i,int j)
{
	printf("%lld %lld %lld\n",b+1,i,j);
	fflush(stdout);
}
#define xz if(cur0y==0)cur0y=2;if(cur1y==0)cur1y=2;
signed main()
{
	int n=read()+1;
	int cnt=n*n;
	int cnt0=0,cnt1=0;
	int cur0x=1,cur0y=1,cur1x=1,cur1y=2;
	while(cnt--)
	{
		if(cnt1==n*n/2)
		{
			int x=read();
			if(x==0)
			{
				query(2,cur0x,cur0y);
				cur0y+=2;
				if(cur0y>n)cur0x++,cur0y=(cur0y^1)&1;
				xz
			}
			else
			{
				query(0,cur0x,cur0y);
				cur0y+=2;
				if(cur0y>n)cur0x++,cur0y=(cur0y^1)&1;
				xz
			}
		}
		else if(cnt0==(n*n+1)/2)
		{
			int x=read();
			if(x==1)
			{
				query(2,cur1x,cur1y);
				cur1y+=2;
				if(cur1y>n)cur1x++,cur1y=(cur1y^1)&1;
				xz
			}
			else
			{
				query(1,cur1x,cur1y);
				cur1y+=2;
				if(cur1y>n)cur1x++,cur1y=(cur1y^1)&1;
				xz
			}
		}
		else
		{
			int x=read();
			if(x==0)
			{
				cur1++;
				query(1,cur1x,cur1y);
				cur1y+=2;
				if(cur1y>n)cur1y=(cur1y^1)&1,cur1x++;
				xz
			}
			else
			{
				cur0++;
				query(0,cur0x,cur0y);
				cur0y+=2;
				if(cur0y>n)cur0y=(cur0y^1)&1,cur0x++;
				xz
			}
		}
	}
    return 0;
}