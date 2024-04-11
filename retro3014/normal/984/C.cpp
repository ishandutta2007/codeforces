#include <iostream>
#include <stdio.h>
#include <vector>

typedef long long ll;
int T;
ll N, M, Z;


ll gcd(ll x, ll y)
{
    if(x==0)    return y;
    return gcd(y%x, x);
}


int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lld %lld %lld", &N, &M, &Z);
        if(N==0)
        {
            printf("Finite\n");
        }
        else
        {
            ll dv=gcd(N, M);
            N/=dv;
            M/=dv;
            dv=gcd(M, Z);
            while(dv!=1)
            {
                while(M%dv==0)
                {
                    M/=dv;
                }
                dv=gcd(M, Z);
            }
            if(M==1)
            {
                printf("Finite\n");
            }
            else
            {
                printf("Infinite\n");
            }
        }
    }
    return 0;
}