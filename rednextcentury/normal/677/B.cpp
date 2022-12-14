#include <iostream>
using namespace std;
int a[1000000];
int main()
{
    int n,h,k;
    cin>>n>>h>>k;
    for (int i=0;i<n;i++)
        cin>>a[i];
    int cur=0;
    long long ans=0;
    for (int i=0;i<n;)
    {
        while(cur+a[i]<=h && i<n)
            cur+=a[i],i++;
        if (i==n)break;
        int need=h-a[i];
        int d=cur-need;
        cur=max(0,cur-((d/k)+(d%k>0))*k);
        ans+=(d/k)+(d%k>0);
    }
    ans+=(cur/k)+(cur%k>0);
    cout<<ans<<endl;
}