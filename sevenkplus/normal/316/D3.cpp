#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
#define P 1000000007
#define N 1000010
int Fac[N],IFac[N];
void gcd2(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1,y=0;
        return;
    }
    gcd2(b,a%b,x,y);
    ll t=x;
    x=y,y=t-a/b*y;
}
int Inv(int n)
{
    ll x,y;
    gcd2(n,P,x,y);
    if(x<0)
        return x+P;
    else
        return x;
}
const int Inv2=Inv(2);
int n,m;
int main()
{
    Fac[0]=IFac[0]=1;
    for(int i=1;i<N;i++)
        Fac[i]=(ll)Fac[i-1]*i%P;
    IFac[N-1]=Inv(Fac[N-1]);
    for(int i=N-2;i>=0;i--)
        IFac[i]=(ll)IFac[i+1]*(i+1)%P;
    int _;scanf("%d",&_);
    while(_--)
    {
        int x;scanf("%d",&x);
        if(x==1)n++;else m++;
    }
    int n1=n;
    int S=1;
    for(int i=1,s=1;i<=n/2;i++)
    {
        s=((ll)s*((ll)n1*(n1-1)/2%P))%P;
        S=(S+(ll)s*IFac[i]%P)%P;
        n1-=2;
    }
    for(int i=0;i<m;i++)
        S=(ll)S*(n+i+1)%P;
    printf("%d\n",S);
    return 0;
}