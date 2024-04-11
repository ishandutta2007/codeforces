#include<Bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const int N = 1e5 + 11;

int a[N];

int main()
{
    int n,m,l;
    cin>>n>>m>>l;
    for (int i=1; i<=n*m; i++)
        cin>>a[i];
    sort(a+1,a+n*m+1);
    vector<int> vv;
    int k=0;
    for (int i=1; i<=n*m; i++)
    if (a[i]-a[1]<=l) k=i;
    if (k<n) {cout<<0<<endl; return 0;}
    for (int j=k; j>=k-n+2; j--)
        vv.pb(j);
    vector<int> dd;
    dd.pb(1);
    for (int j=0; j<dd.size(); j++)
    {
        int pos=dd[j];
        if (vv.size()>0&&vv.back()>pos+m)
        {
            vv.pop_back();
            dd.pb(pos+m);
        }
    }
    ll ans=0;
    for (int j=0; j<dd.size(); j++)
    {
        //cout<<dd[j]<<" ";
        ans+=1ll*a[dd[j]];
    }
    //cout<<"   ";
    for (int j=0; j<vv.size(); j++)
    {
        ans+=1ll*a[vv[j]];
        //cout<<vv[j]<<" ";
    }
    //cout<<"    ";
    cout<<ans<<endl;
}