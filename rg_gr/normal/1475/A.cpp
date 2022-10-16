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
signed main()
{
    int T=read();
    while(T--)
    {
        int n=read();
        while(n>1)
        {
            if(n&1){puts("YES");break;}
            n>>=1;
        }
        if(n==1)puts("NO");
    }
}