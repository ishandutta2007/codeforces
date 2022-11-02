#include<cstdio>

using namespace std;

int power(int x,long long m,int mo)
{
    int nowans=1;
    while(m)
    {
        if(m&1)nowans=1ll*nowans*x%mo;
        x=1ll*x*x%mo;
        m>>=1;
    }
    return nowans;
}

int t,k,p,q,n;
long long l,r;

int main()
{
    //freopen("1.in","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%I64d%I64d%d",&k,&l,&r,&p);
        if(p==2)
        {
            if(k&1)puts("0");
            else puts("1");
            continue;
        }
        if(k%2==0)
        {
            q=power(k,power(2,l,p-1),p);
            n=power(2,r-l+1,p-1);
            if(!q||k%p==0)
            {
                puts("1");
                continue;
            }
            if(q==1)printf("%d\n",power(2,r-l+1,p)%p);
            else printf("%d\n",(int)(1ll*(power(q,n,p)-1+p)*power(q-1,p-2,p)%p));
        }
        else
        {
            q=power(k,power(2,l,p-1),p);
            n=power(2,r-l+1,p-1);
            if(!q||k%p==0)
            {
                printf("%d\n",power(power(2,(r-l),p),p-2,p));
                continue;
            }
            if(q==1)printf("%d\n",(int)(1ll*power(2,r-l+1,p)*power(power(2,(r-l),p),p-2,p)%p));
            else printf("%d\n",(int)(1ll*(power(q,n,p)-1+p)*power(q-1,p-2,p)%p*power(power(2,(r-l),p),p-2,p)%p));           
        }
    }
}