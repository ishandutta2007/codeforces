# include<iostream>
# include<set>
#include <ios>
# include <algorithm>
using namespace std;
long long nums[1000000];
long long lef=0;
long long a[1000000];
    long long n;
    long long k;
long long bs(long long s,long long e)
{
    long long ans=1;
    while(s<=e)
    {
        long long mid=(s+e)/2;
        if (mid*n-mid*lef<=k)
            ans=max(ans,mid),s=mid+1;
        else
            e=mid-1;
    }
    return ans;
}
long long rem=0;
void decrease(long long val)
{
    while(nums[lef]-rem-val<=0 && lef<n)
        lef++;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    long long sum=0;
    for (long long i=0;i<n;i++)
    {
        cin>>a[i];
        nums[i]=a[i];
        sum+=a[i];
    }
    if (k>sum)
    {
        cout<<-1<<endl;
        return 0;
    }
    if (k==sum)
        return 0;
    sort(nums,nums+n);
    while(k>=0)
    {
        if (k<n-lef)
            break;
        long long j=bs(1,nums[lef]-rem);
        k-=j*(n-lef);
        decrease(j);
        rem+=j;
    }
    for (long long i=0;i<n;i++)
    {
        if (a[i]-rem<=0)
        continue;
        if (k>0)
            {a[i]--;k--;continue;}
        if (a[i]-rem<=0)
            continue;
        cout<<i+1<<" ";
        a[i]=0;
    }
    for (long long i=0;i<n;i++)
    {
        if (a[i]-rem<=0)
        continue;
        cout<<i+1<<" ";
    }
    cout<<endl;
}