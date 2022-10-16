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
inline int reaD()
{
    char c=getchar();
    while(c<97||c>'z')c=getchar();
    return c-97;
}
char a[100005];
int f[100005];
signed main()
{
    int T=read();
    while(T--)
    {
        scanf("%s",a);
        int n=strlen(a);
        memset(f,0,sizeof(int)*(n+3));
        int ans=0;
        if(a[0]==a[1])f[1]=1,ans++;
        for(int i=2;i<n;i++)
        {
            if(a[i]==a[i-2]&&f[i-2]==0)f[i]=1,ans++;
            if(a[i]==a[i-1]&&f[i]==0&&f[i-1]==0)f[i]=1,ans++;
        }
        printf("%lld\n",ans);
    }
}
//425316