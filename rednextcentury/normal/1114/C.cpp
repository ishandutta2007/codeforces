#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,int> > v;
long long n,b;
long long num(long long x)
{
    long long ret=0;
    long long y=x;
    while(x<=n)
    {
        ret+=n/x;
        if (n/x < y)break;
        x=x*y;
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>b;
    for (long long i=2;i*i<=b;i++)
    {
        if (b%i==0)
        {
            pair<long long,int> p = {i,0};
            while(b%i==0)b/=i,p.second++;
            v.push_back(p);
        }
    }
    if (b!=1)v.push_back({b,1});
    long long ret = 1e18;
    for (auto x:v)
        ret=min(ret,num(x.first)/x.second);
    cout<<ret<<endl;
}