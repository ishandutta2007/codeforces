#include<bits/stdc++.h>
using namespace std;

#define y1 ojf
#define ld long double
#define ull unsigned long long
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair


const int N = 5e5 + 11;

vector<int> v[N];
int d[20][N];
int kk,tin[N],tout[N],tim;
int use[N];
int c1[N],c2[N],c3[N];
bool goood[N];
map<pair<int,int>,bool> bad;
vector<pair<int,int> > v1[N];
vector<int> v2[N];
multiset<int> st[N];
int n;
int w[N*4];
int t[N*4];
ll res;
int glava[N];

int gl(int l)
{
    if (l==glava[l]) return l;
    return glava[l]=gl(glava[l]);
}

void build(int i, int l, int r)
{
    w[i]=2e9;
    if (l==r) return;
    int mid=(l+r)>>1;
    build(i+i,l,mid);
    build(i+i+1,mid+1,r);
}

void update(int i, int l, int r, int x, int t)
{
    if (l==r) {w[i]=t; return;}
    int mid=(l+r)>>1;
    if (x<=mid) update(i+i,l,mid,x,t); else update(i+i+1,mid+1,r,x,t);
    w[i]=min(w[i+i],w[i+i+1]);
}

int get(int i, int l, int r, int tl, int tr)
{
    if (tl<=l&&r<=tr) return w[i];
    if (tl>r||l>tr) return 2e9;
    int mid=(l+r)>>1;
    return min(get(i+i,l,mid,tl,tr),get(i+i+1,mid+1,r,tl,tr));
}

void dfs(int l, int pr)
{
    tim++;
    tin[l]=tim;
    d[0][l]=pr;
    use[l]=kk;
    for (int j=1; j<20; j++)
        d[j][l]=d[j-1][d[j-1][l]];
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr) dfs(v[l][j],l);
    tout[l]=tim;
}

void up(int l, int r, int k)
{
    //cout<<l<<"->"<<r<<" "<<k<<endl;
    v1[l].pb(mp(r,k));
    v2[r].pb(k);
}

void dfs2(int l, int pr)
{
    //cout<<l<<" "<<pr<<endl;
    use[l]=1;
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr) dfs2(v[l][j],l);
    for (int p=0; p<v2[l].size(); p++)
    {
        st[l].insert(v2[l][p]);
    }
    if (st[l].size()!=0)
    {
        t[l]=*st[l].begin();
        update(1,1,n,tin[l],t[l]);
    }
    if (l!=1&&bad[mp(pr,l)]==0)
    {
        ll c=1ll*get(1,1,n,tin[l],tout[l]);
        if (c==2000000000) {cout<<-1<<endl; exit(0);}
        res+=c;
    }
    for (int p=0; p<v1[l].size(); p++)
    {
        int r=v1[l][p].ff;
        st[r].erase(st[r].find(v1[l][p].ss));
        if (v1[l][p].ss==t[r])
        {
            if (st[r].size()==0) t[r]=2e9; else t[r]=*st[r].begin();
            update(1,1,n,tin[r],t[r]);
        }
    }
}

bool predok(int l, int r)
{
    if (tin[l]<=tin[r]&&tout[r]<=tout[l]) return true;
    return false;
}

pair<int,int> lca(int l, int r)
{
    if (predok(l,r))
    {
        for (int j=19; j>=0; j--)
            if (d[j][r]!=0&&d[j][r]!=l&&predok(l,d[j][r])) r=d[j][r];
        return mp(-1,r);
    }
    if (predok(r,l))
    {
        for (int j=19; j>=0; j--)
            if (d[j][l]!=0&&d[j][l]!=r&&predok(r,d[j][l])) l=d[j][l];
        return mp(l,-1);
    }
    int x=l,y=r;
    for (int j=19; j>=0; j--)
        if (d[j][l]!=0&&(!predok(d[j][l],r))) l=d[j][l];
    swap(x,l);
    for (int j=19; j>=0; j--)
        if (d[j][r]!=0&&(!predok(d[j][r],l))) r=d[j][r];
    swap(y,r);
    return mp(x,y);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k,m;
    cin>>n>>k>>m;
    for (int i=1; i<=n; i++)
        glava[i]=i;
    for (int i=1; i<=k; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
        int x=gl(l);
        int y=gl(r);
        glava[x]=y;
    }
    for (int i=1; i<=m; i++)
    {
        cin>>c1[i]>>c2[i]>>c3[i];
        int l=c1[i],r=c2[i],pp=c3[i];
        int x=gl(l),y=gl(r);
        if (x!=y)
        {
            goood[i]=1;
            bad[mp(l,r)]=1;
            bad[mp(r,l)]=1;
            glava[x]=y;
            v[l].pb(r);
            v[r].pb(l);
            //cout<<"+ "<<l<<" "<<r<<endl;
        }
    }
    build(1,1,n);
    dfs(1,0);
    for (int i=1; i<=m; i++)
    {
        int l=c1[i],r=c2[i],pp=c3[i];
        if (goood[i]==0)
        {
            pair<int,int> p=lca(l,r);
            if (p.ff!=-1) up(p.ff,l,pp);
            if (p.ss!=-1) up(p.ss,r,pp);
        }
    }
    for (int i=1; i<=n; i++)
        use[i]=0;
    dfs2(1,0);
    cout<<res<<endl;
}
/**
5 2 3
1 2
4 5
2 3 100
3 4 100
1 5 1000

1
2

3

4
5


1
2
3
5
4
**/