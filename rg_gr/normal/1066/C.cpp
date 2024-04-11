#include <stdio.h>
#include <map>
#include <algorithm>
#include <string.h>
#define int long long
inline int read()
{
    int f=1,num=0;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=num*10+(c^48),c=getchar();
    return num*f;
}
char gc()
{
    char c=getchar();
    while(c!='L'&&c!='R'&&c!='?')c=getchar();
    return c;
}
std::map<int,int> m;
signed main()
{
    int T=read(),L=0,R=-1;
    while(T--)
    {
        char c=gc();int d=read();
        if(c=='L')
        {
            m[d]=--L;
        }
        else if(c=='R')m[d]=++R;
        else
        {
            int x=m[d];
            int ll=x-L,rr=R-x;
            printf("%lld\n",ll<rr?ll:rr);
        }
        
    }
    //printf("%lld\n",ans);
}