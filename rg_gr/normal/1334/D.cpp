#include <stdio.h>
#include <string.h>
#include <algorithm>
#define int long long
inline int read()
{
	int num=0;char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
	return num;
}
void print(int s,int i,int line)
{
	i-=s;
	if(i&1)printf("%lld ",(i+1)/2+line);
	else printf("%lld ",line);
}
signed main()
{
	int T=read();
	while(T--)
	{
		int n=read(),ll=read(),r=read();
		int l=1,st=1;
		for(int i=ll;i<=r;i++)
		{
			if(i==n*(n-1)+1)
			{
				printf("1 ");
				break;
			}
			while(st+(n-l)*2<=i)st+=(n-l)*2,l++;
			print(st,i,l);
		}
		puts("");
	}
}