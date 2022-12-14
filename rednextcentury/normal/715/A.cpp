#include<bits/stdc++.h>
using namespace std;
long long GCD(long long a,long long b)
{
    if (a%b==0)return b;
    if (b%a==0)return a;
    return GCD(b%a,a);
}
long long LCM(long long a,long long b)
{
    return (a/(GCD(a,b)))*b;
}
int main()
{
    int n;
    cin>>n;
    long long cur=2;
    for (int i=1;i<=n;i++)
    {
        long long x=LCM(i,i+1);
        printf("%I64d\n",(x/i)*x-cur/i);
        cur=x;
    }
}