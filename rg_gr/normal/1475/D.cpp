#include <queue>
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
inline int max(int a,int b){return a>b?a:b;}
int a[200005],b[200005],ca,cb,q[200005];
int cmo(int a,int b)
{
    return a>b;
}
signed main()
{
    int T=read();
    while(T--)
    {
        int n=read(),k=read();
        ca=cb=0;
        for(int i=0;i<n;i++)i[q]=read();
        for(int i=0;i<n;i++)
        {
            int p=read();
            if(p==1)a[ca+1]=q[i],ca++;
            else b[cb+1]=q[i],cb++;
        }
        std::sort(a+1,a+ca+1,cmo);
        std::sort(b+1,b+cb+1,cmo);
        for(int i=1;i<=cb;i++)b[i]+=b[i-1];
        for(int i=1;i<=ca;i++)a[i]+=a[i-1];
        if(a[ca]+b[cb]<k){puts("-1");continue;}
        int ans=0x3f3f3f3f3f3f3f3fll;
        for(int i=0;i<=ca;i++)
        {
            int v=k-a[i];
            int aa=0;
            if(v>0)
            {
                aa=std::lower_bound(b+1,b+1+cb,v)-b;
                if(aa>cb)continue;
            }
            int res=i+aa*2;
            ans=ans<res?ans:res;
        }
        if(ans==0x3f3f3f3f3f3f3f3fll)puts("-1");
        else printf("%lld\n",ans);
    }
}