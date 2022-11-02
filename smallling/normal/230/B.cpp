#include<cstdio>
#include<cmath>

using namespace std;

long long o;
int n;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&o);
        if(o==1){printf("NO\n");continue;}
        long long p=sqrt(o);
        int p1=0;
        if(p*p!=o){printf("NO\n");continue;}
        for(long long j=2;j*j<=p;j++)
        if(o%j==0)
        {
            p1=1;
            break;
        }
        if(p1==0)printf("YES\n");
        else printf("NO\n");
    }
}