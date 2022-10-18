#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

const int N = 100 + 11;

int use[N][N];
char a[N][N],b[5];
vector<pair<int,int> > v,w;
vector<int> vv;

void dfs(int l, int r)
{
    use[l][r]=1;
    v.pb(mp(l,r));
    if (a[l][r]=='F') {w=v; return;}
    if (use[l-1][r]==0&&(a[l-1][r]=='.'||a[l-1][r]=='F')) dfs(l-1,r);
    if (use[l+1][r]==0&&(a[l+1][r]=='.'||a[l+1][r]=='F')) dfs(l+1,r);
    if (use[l][r-1]==0&&(a[l][r-1]=='.'||a[l][r-1]=='F')) dfs(l,r-1);
    if (use[l][r+1]==0&&(a[l][r+1]=='.'||a[l][r+1]=='F')) dfs(l,r+1);
    v.pop_back();
}
int main()
{
    int n,m;
    cin>>n>>m;
    int l,r;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    {
        cin>>a[i][j];
        if (a[i][j]=='F') {l=i; r=j;}
    }
    b[1]='L';
    b[2]='R';
    b[3]='U';
    b[4]='D';
    dfs(1,1);
    for (int i=1; i<w.size(); i++)
    {
        if (w[i].ff==w[i-1].ff)
        {
            if (w[i].ss==w[i-1].ss-1) vv.pb(1); else vv.pb(2);
        } else
        if (w[i].ff==w[i-1].ff-1) vv.pb(3); else vv.pb(4);
    }
    int u1=0,u2=0;
    int x=1,y=1;
    for (int i=0; i<vv.size(); i++)
    {
        if (vv[i]==2&&u1==0)
        {
            cout<<"R"<<endl;
            int xx,yy;
            cin>>xx>>yy;
            u1=1;
            if (x==xx&&y==yy) {swap(b[1],b[2]); cout<<"L"<<endl; cin>>x>>y;}
        } else
        if (vv[i]==4&&u2==0)
        {
            cout<<"D"<<endl;
            int xx,yy;
            cin>>xx>>yy;
            u2=1;
            if (x==xx&&y==yy) {swap(b[3],b[4]); cout<<"U"<<endl; cin>>x>>y;}
        } else
        {
            cout<<b[vv[i]]<<endl;
            cin>>x>>y;
        }
    }

}