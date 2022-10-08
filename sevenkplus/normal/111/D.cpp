#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
#define P 1000000007
int n,m,k,a[1010][1010],F[1000010],G[1000010],S=0;
void gcd2(ll a,ll b,ll&x,ll&y)
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
int inv(int n)
{
    ll x,y;
    gcd2(n,P,x,y);
    if(x<0)return x+P;
    else return x;
}
int ff(int a,int b)
{
    ll s=1,t=a;
    while(b)
    {
        if(b&1)s*=t,s%=P;
        t*=t,t%=P,b/=2;
    }
    return s;
}
int C(int n,int k){return (ll)F[n]*G[k]%P*G[n-k]%P;}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    if(m==1){printf("%d\n",ff(k,n*m));return 0;}
    a[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            a[i][j]=((ll)a[i-1][j-1]+(ll)a[i-1][j]*j)%P;
    F[0]=1;for(int i=1;i<=1000000;i++)F[i]=(ll)F[i-1]*i%P;
    G[1000000]=inv(F[1000000]);
    for(int i=999999;i>=0;i--)G[i]=(ll)G[i+1]*(i+1)%P;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)a[i][j]=(ll)a[i][j]*F[j]%P;
    for(int i=0;i<=min(n,k);i++)
    {
        int T=ff(i,n*(m-2));
        for(int j=0;j<=min(n-i,(k-i)/2);j++)
        {
            //Left * Right  ==  i
            //Left - Right  ==  Right - Left  ==  j
            //S=((ll)S+(ll)C(k,i)*C(n,i)%P*C(n,i)%P*a[n][i]%P*C(k-i,j)%P*C(k-i-j,j)%P*a[n][j]%P*a[n][j]%P*T%P)%P;
            S=((ll)S+(ll)C(k,i)*a[n][i+j]%P*a[n][i+j]%P*C(k-i,j)%P*C(k-i-j,j)%P*T%P)%P;
        }
    }
    printf("%d\n",S);
    return 0;
}