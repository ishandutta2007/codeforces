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
    return (a/GCD(a,b))*b;
}
pair<long long,long long> operator+(pair<long long,long long> a,pair<long long,long long> b)
{
    pair<long long,long long> ret;
    long long L=LCM(a.second,b.second);
    ret.first=a.first*(L/a.second)+(L/b.second)*b.first;
    ret.second=L;
    return ret;
}
pair<long long,long long> operator-(pair<long long,long long> a,pair<long long,long long> b)
{
    pair<long long,long long> ret;
    long long L=LCM(a.second,b.second);
    ret.first=a.first*(L/a.second)-(L/b.second)*b.first;
    ret.second=L;
    return ret;
}
bool prime(long long n)
{
    for (int i=2;i*i<=n;i++)
        if (n%i==0)return 0;
    return 1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long h=n+1;
        while(!prime(h))h++;
        long long k=n;
        while(!prime(k))k--;
        pair<long long,long long> ret;
        if (h-n-1!=0)
            ret=make_pair(1LL,2LL)-make_pair(1LL,k+0LL)+make_pair(n-k+1,h*k);
        else ret=make_pair(1LL,2LL)-make_pair(1LL,h+0LL);
            cout<<ret.first<<'/'<<ret.second<<endl;
    }
}