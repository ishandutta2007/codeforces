#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int N = 2e5 + 11;

vector<int> v[N];
int use[N],sz[N],mx[N],deep[N];
int dist[20][N],pr[20][N];
int min_dist[N];
vector<int> prr[N],distt[N];
vector<int> vv;

void dfs1(int l)
{
    use[l]=1;
    vv.pb(l);
    sz[l]=1;
    mx[l]=0;
    for (int j=0; j<v[l].size(); j++)
        if (use[v[l][j]]==0)
        {
            dfs1(v[l][j]);
            sz[l]+=sz[v[l][j]];
            mx[l]=max(mx[l],sz[v[l][j]]);
        }
}

void dfs2(int l, int p, int dis)
{
    use[l]=1;
    prr[l].pb(p);
    distt[l].pb(dis);
    for (int j=0; j<v[l].size(); j++)
        if (use[v[l][j]]==0) dfs2(v[l][j],p,dis+1);
}

int build(int l, int dd)
{
    vv.clear();
    dfs1(l);
    int p=vv[0],t=2e9;
    for (int j=0; j<vv.size(); j++)
    {
        use[vv[j]]=0;
        int g=max(mx[vv[j]],(int)vv.size()-sz[vv[j]]);
        if (g<t)
        {
            t=g;
            p=vv[j];
        }
    }
    int centr=p;
    dfs2(centr,centr,0);
    for (int j=0; j<vv.size(); j++)
        use[vv[j]]=0;
    use[centr]=2;
    deep[centr]=dd;
    for (int j=0; j<prr[centr].size(); j++)
    {
        int x=prr[centr][j];
        int dis=distt[centr][j];
        pr[deep[x]][centr]=x;
        dist[deep[x]][centr]=dis;
        //cout<<centr<<" "<<deep[x]<<" - "<<x<<"("<<dis<<")"<<endl;
    }
    for (int j=0; j<v[centr].size(); j++)
        {
            int p=v[centr][j];
            if (use[p]==0)
            {
                int x=build(p,dd+1);
                //cout<<centr<<"-->"<<x<<endl;
            }
        }
    return centr;
}

void update(int l)
{
    for (int p=0; p<=deep[l]; p++)
    {
        int x=pr[p][l];
        min_dist[x]=min(min_dist[x],dist[p][l]);
    }
}

int get(int l)
{
    int ans=1e9;
    for (int p=0; p<=deep[l]; p++)
    {
        int x=pr[p][l];
        ans=min(ans,min_dist[x]+dist[p][l]);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    int gl=build(1,0);
    //cout<<"! "<<gl<<endl;
    for (int i=1; i<=n; i++)
        min_dist[i]=1e9;
    update(1);
    for (int i=1; i<=m; i++)
    {
        int t,x;
        cin>>t>>x;
        if (t==1) update(x); else cout<<get(x)<<"\n";
    }
}
/**
10 1
10 7
10 6
1 4
7 8
5 1
6 2
7 5
6 3
7 9

2 9



2 8
2 2
2 7
2 6
2 8
2 1
2 6
2 4
**/