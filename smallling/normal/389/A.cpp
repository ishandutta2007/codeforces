#include<cstdio>
#include<cstdlib>
using namespace std;
int i,j,k,l,m,n,o,p,a[101],ans;
int gcd(int a,int b)
{
    if(a%b==0)return b;
    if(a<b)return gcd(b,a);
    else return gcd(a%b,b);
}
int main()
{
    scanf("%d",&n);
    scanf("%d",&a[1]);
    ans=a[1];
    for(i=2;i<=n;i++)
    {
                     scanf("%d",&a[i]);
                     ans=gcd(ans,a[i]);
    }
    ans=ans*n;
    printf("%d",ans);
}