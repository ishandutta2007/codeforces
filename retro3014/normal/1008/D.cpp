#include <iostream>
#include <algorithm>
#include <stdio.h>

typedef long long ll;

using namespace std;

ll num(int x){
    ll y=1;
    int k=2;
    ll t=0;
    while(k*k<=x)
    {
        while(x!=1 && x%k==0)
        {
            x/=k;
            t++;
        }
        y*=(t+1);
        t=0;
        k++;
    }
    if(x!=1) y*=2;
    return y;
}

int gcd(int x, int y)
{
    return (x==0)?y:gcd(y%x, x);
}

ll ncr(ll n, ll r)
{
    ll k=1;
    ll k2=1;
    for(ll i=1; i<=r; i++){
        k*=(n-i+1);
        k2*=i;
    }
    return k/k2;
}

int T=0;
ll ans;
int a, b, c;
ll k[10];

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &a, &b, &c);
        k[0]=num(gcd(a, gcd(b, c)));
        k[1]=num(gcd(a, b))-k[0];
        k[2]=num(gcd(a, c))-k[0];
        k[3]=num(gcd(b, c))-k[0];
        k[4]=num(a)-k[1]-k[2]-k[0];
        k[5]=num(b)-k[1]-k[3]-k[0];
        k[6]=num(c)-k[3]-k[2]-k[0];
        ll B=num(b);
        ll C=num(c);
        ll L=k[4]+B+C-k[0]-k[3];
        ans=0;
        ans+=ncr(k[0]+2, 3);
        ans+=ncr(k[0]+1, 2)*(L-k[0]);
        ans+=ncr(k[1]+1, 2)*k[0];
        ans+=k[0]*k[1]*(L-k[1]-k[0]);
        ans+=k[0]*ncr(k[2]+1, 2);
        ans+=k[0]*k[2]*(L-k[0]-k[1]-k[2]);
        ans+=k[0]*ncr(k[3]+1, 2);
        ans+=k[0]*k[3]*(L-k[0]-k[1]-k[2]-k[3]);
        ans+=k[0]*k[4]*(k[5]+k[6]);
        ans+=k[0]*k[5]*k[6];
        L-=k[0];
        ans+=ncr(k[1]+1, 2)*(C-k[0]);
        ans+=ncr(k[2]+1, 2)*k[1];
        ans+=k[1]*k[2]*(L-k[1]-k[2]);
        ans+=k[1]*ncr(k[3]+1, 2);
        ans+=k[1]*k[3]*(L-k[1]-k[2]-k[3]);
        ans+=k[1]*k[4]*k[6];
        ans+=k[5]*k[1]*k[6];
        L-=k[1];
        ans+=ncr(k[2]+1, 2)*(B-k[0]-k[1]);
        ans+=k[2]*ncr(k[3]+1, 2);
        ans+=k[2]*k[3]*(L-k[2]-k[3]);
        ans+=k[2]*k[4]*k[5];
        ans+=k[2]*k[5]*k[6];
        L-=k[2];
        ans+=ncr(k[3]+1, 2)*k[4];
        ans+=k[3]*k[4]*(k[5]+k[6]);
        ans+=k[4]*k[5]*k[6];
        printf("%lld\n", ans);
    }
    
    
}