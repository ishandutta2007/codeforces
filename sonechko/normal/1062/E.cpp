#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 4e5 + 11;
const int MOD = 1e9 + 7;

int tin[N],tout[N],deep[N],tim;
vector<int> v[N];
int v1[N],v2[N],d[20][N];
int pr[N];

void dfs(int l)
{
    for (int j=1; j<20; j++)
        d[j][l]=d[j-1][d[j-1][l]];
    tim++;
    tin[l]=tim;
    for (int j=0; j<v[l].size(); j++)
    {
        deep[v[l][j]]=deep[l]+1;
        d[0][v[l][j]]=l;
        dfs(v[l][j]);
    }
    tout[l]=tim;
}

void build(int i, int l, int r)
{
    if (l==r) {v1[i]=l; v2[i]=l; return;}
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    if (tin[v1[i*2]]<tin[v1[i*2+1]]) v1[i]=v1[i*2]; else v1[i]=v1[i*2+1];
    if (tout[v2[i*2]]>tout[v2[i*2+1]]) v2[i]=v2[i*2]; else v2[i]=v2[i*2+1];
}

pair<int,int> get(int i, int l, int r, int tl, int tr)
{
    if (tl<=l&&r<=tr) return mp(v1[i],v2[i]);
    if (tl>r||l>tr) return mp(0,0);
    int mid=(l+r)/2;
    pair<int,int> p1=get(i*2,l,mid,tl,tr),p2=get(i*2+1,mid+1,r,tl,tr);
    if (tin[p2.ff]<tin[p1.ff]) p1.ff=p2.ff;
    if (tout[p2.ss]>tout[p1.ss]) p1.ss=p2.ss;
    return p1;
}

bool pred(int l, int r)
{
    if (tin[l]<=tin[r]&&tout[l]>=tout[r]) return true;
    return false;
}

int lca(int l, int r)
{
    if (l==0) return r;
    if (r==0) return l;
    if (pred(l,r)) return l;
    if (pred(r,l)) return r;
    for (int j=19; j>=0; j--)
        if (d[j][r]!=0&&(!pred(d[j][r],l))) r=d[j][r];
    return pr[r];
}

int n;

int lcaa(int l, int r)
{
    if (l>r) return 0;
    pair<int,int> p=get(1,1,n,l,r);
    return lca(p.ff,p.ss);
}

int main()
{
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      int q;
      cin>>n>>q;
      tin[0]=2e9;
      for (int i=2; i<=n; i++)
      {
          int l;
          cin>>l;
          pr[i]=l;
          v[l].pb(i);
      }
      dfs(1);
      build(1,1,n);
      for (int i=1; i<=q; i++)
      {
          int l,r;
          cin>>l>>r;
          pair<int,int> p=get(1,1,n,l,r);
          int ans1=lca(lcaa(l,p.ff-1),lcaa(p.ff+1,r));
          int ans2=lca(lcaa(l,p.ss-1),lcaa(p.ss+1,r));
          if (deep[ans1]>deep[ans2]) cout<<p.ff<<" "<<deep[ans1]<<"\n"; else
          cout<<p.ss<<" "<<deep[ans2]<<"\n";
      }
}