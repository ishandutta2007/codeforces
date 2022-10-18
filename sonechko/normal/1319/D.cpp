#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long

const int N = 2e5 + 11;

int a[N];
vector<int> v1[N],v2[N];
int dist[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        v1[l].pb(r);
        v2[r].pb(l);
    }
    int k;
    cin>>k;
    for (int i=1; i<=k; i++)
        cin>>a[i];
    vector<int> vv;
    vv.pb(a[k]);
    for (int i=1; i<=n; i++)
        dist[i]=-1;
    dist[a[k]]=0;
    for (int j=0; j<vv.size(); j++)
    {
        int l=vv[j];
        for (int j=0; j<v2[l].size(); j++)
            if (dist[v2[l][j]]==-1)
        {
            dist[v2[l][j]]=dist[l]+1;
            vv.pb(v2[l][j]);
        }
    }
    int m1=0,m2=0;
    for (int i=1; i<k; i++)
    {
        int l=a[i];
        int r=a[i+1];
        ///cout<<l<<" -> "<<r<<endl;
        if (dist[l]!=dist[r]+1)
        {
            m1++;
            m2++;
        } else
        {
            int kk=0;
            for (int j=0; j<v1[l].size(); j++)
                if (dist[l]==dist[v1[l][j]]+1) kk++;
            if (kk>1) m2++;
        }
    }
    cout<<m1<<" "<<m2;
}