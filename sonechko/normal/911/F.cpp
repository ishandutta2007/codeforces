#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair

const int N = 2e5 + 11;

int t,dist,L,R,kol[N],use[N];
int dist1[N],dist2[N];
vector<int> v[N];

void dfs(int l, int r, int pr)
{
    if (r>dist) {dist=r; t=l;}
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr) dfs(v[l][j],r+1,l);
}
void dfs2(int l, int ds, int pr, int kk)
{
    if (kk==0) dist1[l]=ds; else dist2[l]=ds;
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr) dfs2(v[l][j],ds+1,l,kk);
}

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    t=1;
    dist=0;
    dfs(1,0,0);
    dist=0;
    L=t;
    dfs(t,0,0);
    R=t;
    dfs2(L,0,0,0);
    dfs2(R,0,0,1);
    vector<int> vv;
    for (int i=1; i<=n; i++)
        kol[i]=v[i].size();
    for (int i=1; i<=n; i++)
        if (kol[i]==1) vv.pb(i);
    ll ans=0;
    vector<pair<int,int> > res;
    for (int j=0; j<vv.size(); j++)
        if (vv[j]!=L&&vv[j]!=R)
    {
        int to=vv[j];
        if (dist1[to]>dist2[to])
        {
            ans+=1ll*dist1[to];
            res.pb(mp(L,to));
        } else
        {
            ans+=1ll*dist2[to];
            res.pb(mp(R,to));
        }
        for (int p=0; p<v[to].size(); p++)
        {
            kol[v[to][p]]--;
            if (kol[v[to][p]]==1) vv.pb(v[to][p]);
        }
        use[to]=1;
    }
    while (L!=R)
    {
        ans+=1ll*dist1[R];
        use[R]=1;
        res.pb(mp(L,R));
        for (int j=0; j<v[R].size(); j++)
        if (use[v[R][j]]==0) {R=v[R][j]; break;}
    }
    cout<<ans<<"\n";
    for (int j=0; j<res.size(); j++)
        cout<<res[j].ff<<" "<<res[j].ss<<" "<<res[j].ss<<"\n";

}