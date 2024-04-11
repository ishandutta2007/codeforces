#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

const int N = 1e5 + 11;

map<string,int> mt;
string ss[N];
int a[N];

int main()
{
    int n,k,m;
    cin>>n>>k>>m;
    for (int i=1; i<=n; i++)
    {
        cin>>ss[i];
        mt[ss[i]]=i;
    }
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int d=1; d<=k; d++)
    {
        int pp;
        cin>>pp;
        vector<int> vv;
        int cc=1e9;
        for (int j=1; j<=pp; j++)
        {
            int l;
            cin>>l;
            cc=min(cc,a[l]);
            vv.pb(l);
        }
        for (int j=0; j<vv.size(); j++)
            a[vv[j]]=cc;
    }
    ll ans=0;
    for (int i=1; i<=m; i++)
    {
        string s;
        cin>>s;
        ans+=1ll*a[mt[s]];
    }
    cout<<ans<<endl;
}