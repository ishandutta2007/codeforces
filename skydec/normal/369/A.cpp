#include<stdio.h>
using namespace std;
long n,m,k;
long ans=0;
int main()
{
    scanf("%ld%ld%ld",&n,&m,&k);
    for(long i=1;i<=n;i++)
    {
        long a;scanf("%ld",&a);
        if(a==1)
        {
            if(m==0)ans++;else m--;
        }
        if(a==2)
        {
            if(m==0&&k==0)ans++;
            else if(k==0)m--;
            else k--;
        }
    }
    printf("%ld\n",ans);
    return 0;
}