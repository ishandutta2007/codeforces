#include<cstdio>

long long l,r;
int t;

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d%I64d",&l,&r);
        for(int i=1;i<=60;i++)
            if(((l&(1ll<<(i-1)))==0)&&((l|(1ll<<(i-1)))<=r))l|=(1ll<<(i-1));
        printf("%I64d\n",l);
    }
}