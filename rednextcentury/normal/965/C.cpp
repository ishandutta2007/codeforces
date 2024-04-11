#include<bits/stdc++.h>
using namespace std;
long long n,k,m,d;
bool can(long long x)
{
    long long cur=0;
    for (int i=0;i<x-1;i++)
    {
        cur+=k;
        if (cur>n || cur<0)
            return false;
    }
    return cur<n;
}
int main()
{
    cin>>n>>k>>m>>d;
    long long ret=0;
    for (long long i=1;i<=d;i++)
    {
        if (can(i))
        {
            long long tot = k*(i-1)+1;
            long long num = n/tot;
            num=min(num,m);
            ret = max(ret, num*i);
        }
    }
    cout<<ret<<endl;
}