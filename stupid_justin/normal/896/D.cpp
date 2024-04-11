#include<bits/stdc++.h>
#define int long long
#define I inline
#define rd(x) x=read()
using namespace std;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
const int N=1e5+5;
const int inf=0x3f3f3f3f3f3f3f3f;
                                                                                                                                                            
I int gcd(int x,int y){if (x%y==0) return y;return gcd(y,x%y);}
I int ksm(int x,int y,int z){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n,p,l,r,ans;
int prim[N],inc[N],inv[N],cnt,phi;
int cntinc[N][50];
int C(int a,int b)
{
    if (b<0 || a<b || n<=0) {return 0;}
    if (b==0) {return 1;}
    int ret=inc[a]*inv[b]%p*inv[a-b]%p;
    for (int i=1;i<=cnt;i++) 
        ret=(ret*ksm(prim[i],cntinc[a][i]-cntinc[b][i]-cntinc[a-b][i],p))%p;
    return ret;
}
void init()
{
    int tmp=p;
    phi=p;
    for (int i=2;i<=sqrt(tmp);i++)
    {
        if (tmp%i!=0) continue;
        phi=phi/i*(i-1);
        while (tmp%i==0) tmp/=i;
    }
    if (tmp>1) phi=phi/tmp*(tmp-1);
    inc[0]=inc[1]=1;
    inv[0]=inv[1]=1;
    tmp=p;
    for (int i=2;i<=sqrt(tmp);i++)
    {
        if (tmp%i!=0) continue;
        prim[++cnt]=i;
        while (tmp%i==0) tmp/=i;
    }
    if (tmp>1) prim[++cnt]=tmp;
    for (int i=2;i<=n;i++)
    {
        tmp=i;
        for (int j=1;j<=cnt;j++)
        {
            cntinc[i][j]=cntinc[i-1][j];
            while (tmp%prim[j]==0) tmp/=prim[j],cntinc[i][j]++;
        }
        inc[i]=inc[i-1]*tmp%p;
        inv[i]=ksm(inc[i],phi-1,p);
    }
}
signed main()
{
    rd(n);rd(p);rd(l);rd(r);
    init();
    r=min(n,r);
    for (int i=0;i<=n-l;i++)
    {
        int tmp;
        tmp=(C(n-i,(n-i-l)>>1)-C(n-i,(n-i-r-1)>>1)+p)%p;
        ans+=(tmp*C(n,i))%p;
        ans%=p;
    }
    cout<<(ans+p)%p<<endl;
}