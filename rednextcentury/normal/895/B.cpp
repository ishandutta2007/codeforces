#include <bits/stdc++.h>
using namespace std;
long long a[1000000];
long long x;
long long bef(long long n,bool y=1)
{
    if (y==1)
        return n/x;
    else
        return n/x - (n%x==0);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;long long k;
    cin>>n>>x>>k;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    long long ret=0;
    long long r=0;
    long long l=0;
    long long x1=0,x2=0;
    for (int i=1;i<=n;i++)
    {
        while(a[l]<a[i] || (l<n && bef(a[l])-bef(a[i],0)<k)) { l++; }
        while((r<=n && a[r]<a[i]) || (r<=n && bef(a[r])-bef(a[i],0)<k+1))
        {
            r++;
        }
        if (bef(a[l])-bef(a[i],0)==k)ret+=r-l;
    }
    cout<<ret<<endl;

}