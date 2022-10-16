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
int a[55],b[55];
signed main()
{
    int T=read();
    while(T--)
    {
        memset(b,0,sizeof(b));
        int n=read(),ans=0;
        for(int i=0;i<n;i++)
        {
            a[i]=read();
            for(int j=0;j<i;j++)
            {
                int x=a[i]-a[j];
                x=x>0?x:-x;
                if(b[x])continue;
                b[x]=1;ans++;
            }
        }
        printf("%lld\n",ans);
    }
}
//425316