#include <stdio.h>
#define int unsigned
inline int read()
{
    int f=1,num=0;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=num*10+(c^48),c=getchar();
    return num*f;
}
unsigned C[1005];
inline int inv(int x)
{
    int res=x;
    x*=x;res*=x;
    x*=x;res*=x;
    x*=x;res*=x;
    x*=x;res*=x;
    x*=x;res*=x;
    x*=x;res*=x;
    x*=x;res*=x;
    x*=x;res*=x;
    x*=x;res*=x;
    x*=x;res*=x;
    x*=x;res*=x;
    x*=x;res*=x;
    x*=x;res*=x;
    x*=x;res*=x;
    x*=x;res*=x;
    x*=x;res*=x;
    x*=x;res*=x;
    x*=x;res*=x;
    x*=x;res*=x;
    x*=x;res*=x;
    x*=x;res*=x;
    x*=x;res*=x;
    x*=x;res*=x;
    x*=x;res*=x;
    x*=x;res*=x;
    x*=x;res*=x;
    x*=x;res*=x;
    x*=x;res*=x;
    x*=x;res*=x;
    x*=x;res*=x;
    return res;
}
int p2[1005];
signed main()
{
    int n=read(),p=read(),q=read();
    C[0]=1;
    for(int i=1;i<=p&&i<=n-1;i++)
    {
        C[i]=C[i-1];
        int q=n-i+1;
        p2[i]=p2[i-1];
        while((q^1)&1)p2[i]++,q>>=1;
        int t=i;
        while((t^1)&1)t>>=1,p2[i]--;
        C[i]*=inv(t)*q;
    }
    for(int i=1;i<=p;i++)
    {
        p2[i]&=31;
        C[i]<<=p2[i];
        //printf("%u\n",C[i]);
;    }
    int pq=0,qwq=n-1<p?n-1:p;
    for(int i=1;i<=q;i++)
    {
        int ans=0,o=1;
        for(int j=0;j<=qwq;j++)ans+=o*C[j],o*=i;
        ans*=i;
        pq^=ans;
    }
    printf("%u\n",pq);
}