#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 11;
int a[N],b[N];
vector<pair<int,int> > c;
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int ans=0;
    for (int i=1; i<=n; i++)
    {
       cin>>b[i];
       if (a[i]<b[i]) {m--; ans+=a[i]; a[i]=0; b[i]=0;} else
       {
           c.push_back(make_pair(a[i]-b[i],i));
       }
    }
    sort(c.begin(),c.end());
    for (int i=0; i<m; i++)
    {
        int k=c[i].second;
        ans+=a[k];
        b[k]=0;
        a[k]=0;
    }
    for (int i=1; i<=n; i++)
        ans+=b[i];
    cout<<ans<<endl;
}