#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define F first
#define S second
#define PB push_back
using namespace std;
long long ret=0;
long long L[1000000];
long long R[1000000];
long long sum[1000000];
long long h;
int n;
long long getSum(int l,int r)
{
    if (l>r)return 0;
    if (l==0)return sum[r];
    return sum[r]-sum[l-1];
}
long long getCost(int l,int r)
{
    if (l>=r)return 0;
    return L[r]-R[l]-getSum(l+1,r-1);
}
bool canConnect(int i,int j)
{
    if (j>=n)return 0;
    long long cost = getCost(i,j);
    if (cost>=h)return 0;
    long long cur=getSum(i,j)+h;
    ret=max(ret,cur);
    return 1;
}
int main ()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long last = -1e9;
    cin>>n>>h;
    for (int i=0;i<n;i++)
        cin>>L[i]>>R[i];
    for (int i=0;i<n;i++)
    {
        sum[i]=R[i]-L[i];
        ret=max(ret,R[i]-L[i]+h);
        if (i)sum[i]+=sum[i-1];
    }
    for (int i=0;i<n;i++)
    {
        int j=i;
        for (int x=18;x>=0;x--)
        {
            if (canConnect(i,j+(1<<x)))
                j+=(1<<x);
        }
    }
    cout<<ret<<endl;
}