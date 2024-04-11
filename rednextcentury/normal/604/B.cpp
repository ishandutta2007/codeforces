#include<iostream>
#include<cstring>
#include<algorithm>
#include <map>
#include<vector>
using namespace std;
int a[1000000];
int main()
{
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++)
        cin>>a[i];
    int x=2*k-n;
    int r=n-1-x;
    int l=0;
    int ans=0;
    while(l<r)
    {
        ans=max(ans,a[l]+a[r]);
        l++,r--;
    }
    ans=max(ans,a[n-1]);
    cout<<ans<<endl;
}