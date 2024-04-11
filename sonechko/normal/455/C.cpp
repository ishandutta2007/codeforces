#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 11;
#define pb push_back

int glava[N],maxdist[N],sum[N];
int gg,use[N],dd,KOR;
vector<int> v[N];
void dfs(int l, int r)
{
    sum[gg]++;
    use[l]=1;
    glava[l]=gg;
    if (r>dd) {dd=r; KOR=l;}
    for (int j=0; j<v[l].size(); j++)
        if (use[v[l][j]]==0)
    {
        dfs(v[l][j],r+1);
    }
}
void rec(int l, int r)
{
    use[l]=2;
    if (r>dd) dd=r;
    for (int j=0; j<v[l].size(); j++)
        if (use[v[l][j]]==1)
    {
        rec(v[l][j],r+1);
    }
}
int gl(int l)
{
    if (l==glava[l]) return l;
    glava[l]=gl(glava[l]);
    return glava[l];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    for (int i=1; i<=n; i++)
    if (use[i]==0) {gg=i; dd=0; KOR=i; dfs(i,0); rec(KOR,0); maxdist[i]=dd;}
    for (int i=1; i<=q; i++)
    {

        int p;
        cin>>p;

        if (p==1)
        {
            int l;
            cin>>l;
            int p=gl(l);
            cout<<maxdist[p]<<"\n";
        } else
        {

            int l,r;
            cin>>l>>r;
            int x=gl(l),y=gl(r);
            if (sum[x]<sum[y]) swap(x,y);
            if (x!=y)
            {glava[y]=x;
            sum[x]+=sum[y];
            maxdist[x]=max(maxdist[x],max(maxdist[y],(maxdist[x]+1)/2+(maxdist[y]+1)/2+1));
            }
        }
    }
}