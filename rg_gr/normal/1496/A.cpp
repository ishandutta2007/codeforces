#include <stdio.h>
#include <string.h> 
#include <queue>
#define int long long
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=num*10+(c^48),c=getchar();
    return num*f;
}
char a[1005];
signed main()
{
    int T=read();
    while(T--)
    {
        int n=read(),k=read();
        scanf("%s",a+1);int cnt=0;
        for(int i=1;i<=n/2;i++)
        {
            if(a[i]==a[n-i+1])cnt++;
            else break;
        }
        if(cnt>=k&&(cnt*2!=n||cnt>k))puts("YES");
        else puts("NO");
    }
}