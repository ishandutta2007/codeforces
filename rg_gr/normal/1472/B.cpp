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
int a,b;
signed main()
{
    int T=read();
	while(T--)
	{
		int n=read(),ans=0;a=b=0;
		for(int i=0;i<n;i++)
		{
			int x=read();
			if(x==1)a++;
			else b++;
			ans+=x;
		}
		if(ans&1)puts("NO");
		else if((ans&3)&&a==0)puts("NO");
		else puts("YES");
	}
}