#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

vector<int> v[N];
int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    vector<pair<int,int> > vv;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        vv.pb(mp(a[i],i));
    }
    sort(vv.begin(),vv.end());
    for (int j=0; j<vv.size(); j++)
    {
        vector<int> ps;
        int l=vv[j].ss;
        for (int i=0; i<v[l].size(); i++)
            ps.pb(a[v[l][i]]);
        sort(ps.begin(),ps.end());
        int x=1;
        for (int j=0; j<ps.size(); j++)
            if (ps[j]==x) x++;
        if (vv[j].ff!=x) {cout<<"-1\n"; return 0;}
    }
    for (int j=0; j<vv.size(); j++)
        cout<<vv[j].ss<<" ";
    cout<<endl;
}