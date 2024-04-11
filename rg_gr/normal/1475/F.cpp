#include <string.h> 
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){f=c=='-'?-1:f,c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
inline int rds()
{
    char c=getchar();
    while(c!=48&&c!=49)c=getchar();
    return c&1;
}
int a[1005][1005];
signed main()
{
    int T=read();
    while(T--)
    {
        int n=read();
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)a[i][j]=rds();
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)a[i][j]^=rds();
        for(int i=1;i<n;i++)
            for(int j=0;j<n;j++)a[i][j]^=a[0][j];
        for(int i=1;i<n;i++)
        {
            int p=0;
            for(int j=0;j<n;j++)p+=a[i][j];
            if(p==0||p==n)continue;
            else goto ng;
        }
        puts("YES");
        continue;
        ng:;
        puts("NO");
    }
}