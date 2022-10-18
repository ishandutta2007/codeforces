#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 1e5 + 11;

int dist[101][N];
vector<int> v[N];
int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,s,k;
    cin>>n>>m>>k>>s;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int j=1; j<=m; j++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    for (int ii=1; ii<=k; ii++)
    {
        vector<int> vv;
        for (int j=1; j<=n; j++)
        if (a[j]==ii) {vv.pb(j); dist[ii][j]=0;} else
        dist[ii][j]=1e9;
        for (int j=0; j<vv.size(); j++)
        {
            int l=vv[j];
            for (int i=0; i<v[l].size(); i++)
                if (dist[ii][v[l][i]]>dist[ii][l]+1)
            {
                dist[ii][v[l][i]]=dist[ii][l]+1;
                vv.pb(v[l][i]);
            }
        }
    }
    for (int i=1; i<=n; i++)
    {
        vector<int> vvv;
        for (int j=1; j<=k; j++)
        {
            vvv.pb(dist[j][i]);
        }
        sort(vvv.begin(),vvv.end());
        ll res=0;
        for (int d=0; d<s; d++)
        {
            res+=vvv[d];
        }
        cout<<res<<" ";
    }
}