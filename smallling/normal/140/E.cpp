#include<cstdio>
#include<algorithm>

using namespace std;

int n,m,p,ans,now,last;
int a[1000010],c[5010][5010],f[2][1000010],s[5030][5030],fac[5030];

inline void read(int &x)
{
    x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
}

int main()
{
    scanf("%d%d%d",&n,&m,&p);
    for(int i=1;i<=n;i++)
        read(a[i]);
    c[1][1]=m%p;
    for(int i=2;i<=5000;i++)
        for(int j=1;j<=min(i,m);j++)
            c[i][j]=(1ll*c[i-1][j]*(j-1)%p+1ll*c[i-1][j-1]*(m-j+1)%p)%p;
    s[1][1]=1;
    for(int i=2;i<=5000;i++)
    {
        for(int j=1;j<=i;j++)
            s[i][j]=(1ll*s[i-1][j]*(j-1)%p+s[i-1][j-1])%p;
    }
    fac[0]=1;
    for(int i=1;i<=5000;i++)
        fac[i]=1ll*fac[i-1]*i%p;
    for(int i=1;i<=min(a[1],m);i++)
        f[1][i]=c[a[1]][i],(ans+=f[1][i])%=p;
    for(int i=2;i<=n;i++)
    {
        now=i&1;
        last=now^1;
        for(int j=1;j<=a[i-2];j++)f[now][j]=0;
        for(int j=1;j<=min(a[i],m);j++)
        {
            f[now][j]=1ll*ans*c[a[i]][j]%p;
            (f[now][j]+=p-1ll*f[last][j]*s[a[i]][j]%p*fac[j]%p)%=p;
        }
        ans=0;
        for(int j=1;j<=min(a[i],m);j++)
            (ans+=f[now][j])%=p;
    }
    printf("%d",ans);
}