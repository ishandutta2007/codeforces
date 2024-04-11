#include<bits/stdc++.h>
using namespace std;
map<long long,long long> mem;
long long length(long long x)
{
    if (mem[x])return mem[x];
    if (x<=1)return 1;
    return 2*length(x/2)+1;
}
int get(long long x,long long l,long long r,long long v)
{
    if (l==r)return x;
    long long mid=(l+r)/2;
    if (v==mid)return x%2;
    else if (v<mid) return get(x/2,l,mid-1,v);
    else return get(x/2,mid+1,r,v);
}
int main()
{
    long long n,l,r;
    cin>>n>>l>>r;
    long long len=length(n);
    int ret=0;
    for (long long i=l;i<=r;i++)
        if (get(n,1,len,i))
            ret++;
    cout<<ret<<endl;
}