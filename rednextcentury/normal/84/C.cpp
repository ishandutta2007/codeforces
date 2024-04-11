#include<bits/stdc++.h>
using namespace std;
int n,m;
pair< pair<int,int> , int> A[1000000];
int bs(int l,int r,int x)
{
    int ans=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if (A[mid].first.first-A[mid].first.second<=x)
            ans=mid,l=mid+1;
        else
            r=mid-1;
    }
    return ans;
}
int ret[1000000],rett[1000000];
int main()
{
    memset(ret,-1,sizeof(ret));
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>A[i].first.first>>A[i].first.second,A[i].second=i;
    sort(A,A+n);
    cin>>m;
    int ans=0;
    for (int j=0;j<m;j++)
    {
        int x,y;
        cin>>x>>y;
        int i=bs(0,n-1,x);
        if (i>=0 && (x-A[i].first.first)*(x-A[i].first.first)+y*y<=A[i].first.second*A[i].first.second)
            ret[i]=(ret[i]==-1)?(j+1):(min(j+1,ret[i]));
        i--;
        if (i>=0 && (x-A[i].first.first)*(x-A[i].first.first)+y*y<=A[i].first.second*A[i].first.second)
            ret[i]=(ret[i]==-1)?(j+1):(min(j+1,ret[i]));
    }
    for (int i=0;i<n;i++)ans+=ret[i]>=0;
    for (int i=0;i<n;i++)rett[A[i].second]=ret[i];
    cout<<ans<<endl;
    for (int i=0;i<n;i++)cout<<rett[i]<<' ';
    cout<<endl;
}