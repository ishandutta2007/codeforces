#include <stdio.h>
#include <string.h>
#include <algorithm>
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num*f;
}
int a[200005];
int main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=0;i<n;i++)a[i]=read();
		std::sort(a,a+n);
		int cur=0,ans=0;
		for(int i=0;i<n;i++)
		{
			cur++;
			if(a[i]<=cur)ans++,cur=0;
		}
		printf("%d\n",ans);
	}
}