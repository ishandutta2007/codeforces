#include <stdio.h>
#include <string.h> 
#include <math.h>
#include <algorithm>
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
// lcm(n,b)/n
signed main()
{
    int n=read();
    int q=0;
    for(int i=1;i*i<=n;i++)
    {
        if(i*i==n){q++;break;}
        if(n%i==0)q+=2;
    }
    printf("%lld\n",q);
}