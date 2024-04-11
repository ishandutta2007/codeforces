#include <stdio.h>
#include <string.h> 
#include <queue>
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
//int a[1005][1005];
char a[1000005];
char q='z';
signed main()
{
    scanf("%s",a);
    int n=strlen(a);
    for(int i=0;i<n;i++)
    {
        if(q<a[i])
        {
            puts("Ann");
        }
        else 
            q=a[i],puts("Mike");
    }
}