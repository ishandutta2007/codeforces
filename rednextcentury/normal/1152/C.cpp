#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll lcm(ll a,ll b)
{
    return a*b/__gcd(a,b);
}
int main()
{
    ios::sync_with_stdio(false);
    ll a,b;
    cin>>a>>b;
    if (a>b)swap(a,b);
    long long diff = (b-a);
    vector<long long> vec;
    for (int i=1;i*i<=diff;i++)
    {
        if (diff%i==0)
            vec.push_back(i),vec.push_back(diff/i);
    }
    long long ret=0,mn=4e18;
    for (auto gcd:vec)
    {
        long long cur = (gcd - (a%gcd))%gcd;
        long long cc = lcm(a+cur,b+cur);
        if (cc<mn)
        {
            mn=cc,ret=cur;
        }
        else if (cc==mn)
            ret = min(ret,cur);
    }
    cout<<ret<<endl;
}