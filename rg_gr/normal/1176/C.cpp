#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#define int long long
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num*f;
}
inline int min(int a,int b){return a<b?a:b;}
signed main()
{
    int T=1;
    while(T--)
    {
        int n=read();
        int a4=0,a8=0,a15=0,a16=0,a23=0,a42=0,ans=0;
        for(int i=0;i<n;i++)
        {
            int x=read();
            if(x==4)a4++;
            else if(x==8){if(a4<=a8)ans++;else a8++;}
            else if(x==15){if(a8<=a15)ans++;else a15++;}
            else if(x==16){if(a15<=a16)ans++;else a16++;}
            else if(x==23){if(a16<=a23)ans++;else a23++;}
            else if(x==42){if(a23<=a42)ans++;else a42++,a42--,a23--,a16--,a15--,a8--,a4--;}
            else ans++;
        }
        printf("%lld\n",ans+a4+a8+a15+a16+a23+a42);
    }
}