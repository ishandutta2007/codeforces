#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int use[N],uu[N];
vector<int> v[N];
int p3;
map<int,int> mt[N];

void dfs(int l)
{
    if (uu[l]) return;
    uu[l]=1;
    for (int j=0; j<v[l].size(); j++)
        if (use[v[l][j]]!=0)
    {
        if (use[v[l][j]]==use[l]) {cout<<"-1"; exit(0);}
    } else
    {
        int to=v[l][j];
        int x1=0,x2=0,x3=0;
        for (int p=0; p<v[to].size(); p++)
            if (use[v[to][p]]==1) x1=1; else
            if (use[v[to][p]]==2) x2=1; else
            if (use[v[to][p]]==3) x3=1;
        if (x1==1&&x2==1&&x3==1) {cout<<"-1"; exit(0);}
        if (x1==1&&x2==1) {use[to]=3;} else
        if (x1==1&&x3==1) {use[to]=2;} else
        if (x2==1&&x3==1) {use[to]=1;} else
        if (use[l]==1&&x2==0&&x3==0) use[to]=2; else
        if (use[l]==2&&x1==0&&x3==0) use[to]=1; else
        {
            cout<<"-1";
            exit(0);
        }
        if (use[to]==3) p3=1;
    }
    for (int j=0; j<v[l].size(); j++)
        dfs(v[l][j]);

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        int x,y;
        cin>>x>>y;
        mt[x][y]=1;
        mt[y][x]=1;
        v[x].pb(y);
        v[y].pb(x);
    }
    if (v[1].size()==0)
    {
        cout<<"-1"; return 0;
    }
    use[1]=1;
    use[v[1][0]]=2;
    dfs(1);
    for (int i=1; i<=n; i++)
    if (use[i]==0) {cout<<-1; return 0;}
    if (p3==0) {cout<<-1; return 0;}
    vector<int> v1,v2,v3;
    for (int i=1; i<=n; i++)
        if (use[i]==1) v1.pb(i); else
        if (use[i]==2) v2.pb(i); else v3.pb(i);
    for (int i=0; i<v1.size(); i++)
    for (int j=0; j<v2.size(); j++)
    if (mt[v1[i]][v2[j]]==0) {cout<<-1; return 0;}
    for (int i=0; i<v1.size(); i++)
    for (int j=0; j<v3.size(); j++)
    if (mt[v1[i]][v3[j]]==0) {cout<<-1; return 0;}
    for (int i=0; i<v3.size(); i++)
    for (int j=0; j<v2.size(); j++)
    if (mt[v3[i]][v2[j]]==0) {cout<<-1; return 0;}
    for (int i=1; i<=n; i++)
        cout<<use[i]<<" ";
    cout<<endl;
}
/**
1-2 (1 in v1) (2 in v2)
| |
 3 (3 in v3)


**/