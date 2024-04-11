#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 11;
int a[N];

int main()
{
    int n,v;
    cin>>n>>v;
    for (int i=1; i<=n; i++)
    {
        int l,r;
        cin>>l>>r;
        a[l]+=r;
    }
    int ans=0;
    for (int i=1; i<=3001; i++)
    {
        int d=v;
        int p=min(d,a[i-1]);
        d-=p;
        ans+=p;
        p=min(a[i],d);
        ans+=p;
        a[i]-=p;
    }
    cout<<ans<<endl;
}