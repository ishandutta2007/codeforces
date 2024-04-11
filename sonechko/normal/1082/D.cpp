#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;
const int P1 = 31;
const int P2 = 29;
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    ll t=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        t+=1ll*a[i];
    }
    if ((n-1)*2>t) {cout<<"NO"<<endl; return 0;}
    cout<<"YES ";
    vector<int> v1,v2;
    for (int i=1; i<=n; i++)
        if (a[i]==1) v1.pb(i); else v2.pb(i);
    vector<pair<int,int> > vv;
    int ans=v2.size()-1;
    if (v1.size()>0)
    {
        int l=v1.back();
        int r=v2[0];
        vv.pb(mp(l,r));
        v1.pop_back();
        ans++;
    }
    if (v1.size()>0)
    {
        int l=v1.back();
        int r=v2.back();
        vv.pb(mp(l,r));
        v1.pop_back();
        ans++;
    }
    int pos=0;
    for (int i=0; i<v1.size(); i++)
    {
        while (a[v2[pos]]==2)
            pos++;
        vv.pb(mp(v2[pos],v1[i]));
        a[v2[pos]]--;
    }
    for (int i=1; i<v2.size(); i++)
        vv.pb(mp(v2[i-1],v2[i]));
    cout<<ans<<endl;
    cout<<vv.size()<<endl;
    for (int i=0; i<vv.size(); i++)
        cout<<vv[i].ff<<" "<<vv[i].ss<<endl;

}