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
		int w=read(),h=read(),n=read(),ans=1;
		while(w%2==0)w/=2,ans*=2;
		while(h%2==0)h/=2,ans*=2;
		if(ans>=n)puts("YES");
		else puts("NO");
	}
}