#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 4e5 + 11;

int p[N],pp[N],timee,tin[N],tout[N];
vector<int> v[N];
pair<int,int> w[N*4];
int k,c[N];
int t1[N],deep[N];
int h[20][N];
int st[N];


void dfs(int l, int pr)
{
    timee++;
    tin[l]=timee;
    deep[l]=deep[pr]+1;

    k++;
    c[k]=l;
    t1[l]=k;

    for (int j=0; j<v[l].size(); j++)
    {
        dfs(v[l][j],l);
        k++;
        c[k]=l;
    }
    tout[l]=timee;
}

inline int mini(int l, int r)
{
    if (deep[l]<deep[r]) return l;
    return r;
}

inline bool pred(int l, int r)
{
    if (tin[l]<=tin[r]&&tout[r]<=tout[l]) return 1;
    return 0;
}

inline int lca(int l, int r)
{
    if (t1[l]>t1[r]) swap(l,r);
    int p=st[t1[r]-t1[l]+1];
    int lcaa=mini(h[p][t1[l]],h[p][t1[r]-(1<<p)+1]);
    ///cout<<l<<" "<<r<<" - "<<lcaa<<endl;
    return lcaa;
}

bool good(int l, int r, int x, int y)
{
    int p=lca(l,r);
    if (pred(p,x)&&(pred(x,l)||pred(x,r))) {} else return 0;
    if (pred(p,y)&&(pred(y,l)||pred(y,r))) {} else return 0;
    return 1;
}

pair<int,int> mergee(pair<int,int> x, pair<int,int> y)
{
    if (x.ff==0&&x.ss==0) return y;
    if (y.ff==0&&y.ss==0) return x;
    if (x.ff==-1||y.ff==-1) return mp(-1,-1);
    int x1=x.ff,x2=x.ss,x3=y.ff,x4=y.ss;
    if (good(x1,x2,x3,x4)) return mp(x1,x2);
    if (good(x1,x3,x2,x4)) return mp(x1,x3);
    if (good(x1,x4,x2,x3)) return mp(x1,x4);
    if (good(x2,x3,x1,x4)) return mp(x2,x3);
    if (good(x2,x4,x1,x3)) return mp(x2,x4);
    if (good(x3,x4,x1,x2)) return mp(x3,x4);
    return mp(-1,-1);
}

void build(int i, int l, int r)
{
    if (l==r)
    {
        w[i]=mp(pp[l],pp[r]);
        return;
    }
    int mid=(l+r)/2;
    build(i+i,l,mid);
    build(i+i+1,mid+1,r);
    w[i]=mergee(w[i+i],w[i+i+1]);
}

void update(int i, int l, int r, int x, int t)
{
    if (l==r)
    {
        w[i]=mp(t,t);
        return;
    }
    int mid=(l+r)/2;
    if (x<=mid) update(i+i,l,mid,x,t); else update(i+i+1,mid+1,r,x,t);
    w[i]=mergee(w[i+i],w[i+i+1]);
}

pair<int,pair<int,int> > get(int i, int l, int r, pair<int,int> p)
{
    pair<int,int> c=mergee(p,w[i]);
    if (c.ff!=-1) return mp(r,c);
    if (l==r) return mp(l-1,p);
    int mid=(l+r)/2;
    c=mergee(p,w[i+i]);
    if (c.ff!=-1) return get(i+i+1,mid+1,r,c);
    return get(i+i,l,mid,p);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>p[i];
        pp[p[i]]=i;
    }
    for (int i=2; i<=n; i++)
    {
        int c;
        cin>>c;
        v[c].pb(i);
    }
    dfs(1,0);

    for (int j=1; j<=k; j++)
        h[0][j]=c[j];
    for (int p=1; p<20; p++)
    {
        for (int j=1; j<=k-(1<<p)+1; j++)
        {
            h[p][j]=mini(h[p-1][j],h[p-1][j+(1<<(p-1))]);
        }
    }
    st[0]=0;
    st[1]=0;
    for (int j=2; j<=k; j++)
        if ((1<<(st[j-1]+1))<=j) st[j]=st[j-1]+1; else st[j]=st[j-1];

    build(1,0,n-1);
    int q;
    cin>>q;
    for (int j=1; j<=q; j++)
    {
        int t;
        cin>>t;
        if (t==1)
        {
            int l,r;
            cin>>l>>r;
            update(1,0,n-1,p[l],r);
            update(1,0,n-1,p[r],l);
            swap(p[l],p[r]);
        } else
        {
            pair<int,pair<int, int> >  p=get(1,0,n-1,mp(0,0));
            cout<<p.ff+1<<"\n";
        }
    }
}