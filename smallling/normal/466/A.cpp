#include<cstdio>
#include<algorithm>

using namespace std;

int n,m,a,b;

int main()
{
    scanf("%d%d%d%d",&n,&m,&a,&b);
    if(b*1./m<a*1.)
    {
        if(n>=m)printf("%d",n/m*b+min((n%m)*a,b));
        else printf("%d",min(max(n/m,1)*b,n*a));
    }
    else printf("%d",n*a);
}