#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int tin[N],tout[N],timee,deep[N];
ll a[N];
ll v[N*4],w[N*4];
vector<int> vv[N];
int d[20][N];

void dfs(int l, int pr)
{
    timee++;
    tin[l]=timee;
    deep[l]=deep[pr]+1;
    d[0][l]=pr;
    for (int j=1; j<20; j++)
        d[j][l]=d[j-1][d[j-1][l]];
    for (int j=0; j<vv[l].size(); j++)
        if (vv[l][j]!=pr) dfs(vv[l][j],l);
    tout[l]=timee;
}

void push(int i, int l, int r, int mid)
{
    w[i+i]+=w[i];
    w[i+i+1]+=w[i];
    v[i+i]+=w[i]*1ll*(mid-l+1);
    v[i+i+1]+=w[i]*1ll*(r-mid);
    w[i]=0;
}

void update(int i, int l, int r, int tl, int tr, ll x)
{
    if (tl<=l&&r<=tr)
    {
        v[i]+=(r-l+1)*1ll*x;
        w[i]+=x;
        return;
    }
    if (tl>r||l>tr) return;
    int mid=(l+r)/2;
    push(i,l,r,mid);
    update(i+i,l,mid,tl,tr,x);
    update(i+i+1,mid+1,r,tl,tr,x);
    v[i]=v[i+i]+v[i+i+1];
}

ll get(int i, int l, int r, int tl, int tr)
{
    if (tl<=l&&r<=tr) return v[i];
    if (tl>r||l>tr) return 0;
    int mid=(l+r)/2;
    push(i,l,r,mid);
    return get(i+i,l,mid,tl,tr)+get(i+i+1,mid+1,r,tl,tr);
}

inline bool pred(int l, int r)
{
    if (tin[l]<=tin[r]&&tout[r]<=tout[l]) return 1;
    return 0;
}

inline int lca(int l, int r)
{
    if (pred(l,r)) return l;
    if (pred(r,l)) return r;
    for (int j=19; j>=0; j--)
        if (d[j][l]!=0&&(!pred(d[j][l],r))) l=d[j][l];
    return d[0][l];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        vv[l].pb(r);
        vv[r].pb(l);
    }
    dfs(1,0);
    for (int i=1; i<=n; i++)
        update(1,1,n,tin[i],tin[i],a[i]);
    int kor=1;
    for (int i=1; i<=m; i++)
    {
        int t;
        cin>>t;
        if (t==1) cin>>kor; else
        if (t==2)
        {
            int l,r,x;
            cin>>l>>r>>x;
            int p=lca(l,r);
            if (pred(p,kor)&&kor!=p)
            {
                int l1=l;
                for (int j=19; j>=0; j--)
                    if (d[j][l1]!=0&&(pred(d[j][l1],kor)==0))
                    l1=d[j][l1];
                if (pred(l1,kor)==0) l1=d[0][l1];
                int r1=r;
                for (int j=19; j>=0; j--)
                    if (d[j][r1]!=0&&(pred(d[j][r1],kor)==0))
                    r1=d[j][r1];
                if (pred(r1,kor)==0) r1=d[0][r1];
                if (deep[l1]>deep[r1]) p=l1; else p=r1;
            }
            ///cout<<l<<" "<<r<<" - "<<p<<endl;
            if (pred(p,kor)==0)
                update(1,1,n,tin[p],tout[p],x); else
            if (p==kor) update(1,1,n,1,n,x); else
            {
                int c=kor;
                for (int j=19; j>=0; j--)
                    if (d[j][c]!=0&&(pred(d[j][c],p)==0))
                    c=d[j][c];
                update(1,1,n,1,n,x);
                update(1,1,n,tin[c],tout[c],-x);
            }
        } else
        {
            int p;
            cin>>p;
            if (pred(p,kor)==0) cout<<get(1,1,n,tin[p],tout[p])<<"\n"; else
            if (p==kor) cout<<v[1]<<"\n"; else
            {
                int c=kor;
                for (int j=19; j>=0; j--)
                    if (d[j][c]!=0&&(pred(d[j][c],p)==0))
                    c=d[j][c];
                cout<<v[1]-get(1,1,n,tin[c],tout[c])<<"\n";
            }
        }
    }
}