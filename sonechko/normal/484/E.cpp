#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

const int N = 1e5 + 11;

int a[N],gl[N],sz[N];
int ans[N];
map<int,int> mt;

int glava(int l)
{
    if (l==gl[l]) return l;
    return gl[l]=glava(gl[l]);
}

int v[N*60],w[N*60],l1[N*60],r1[N*60],kol,root[N];

void update(int i1, int i2, int l, int r, int x, int y)
{
    if (l==r) {v[i1]=y-l+1; w[i1]=y; return;}
    int mid=(l+r)>>1;
    if (x<=mid)
    {
        kol++;
        l1[i1]=kol;
        r1[i1]=r1[i2];
        update(l1[i1],l1[i2],l,mid,x,y);
    } else
    {
        kol++;
        r1[i1]=kol;
        l1[i1]=l1[i2];
        update(r1[i1],r1[i2],mid+1,r,x,y);
    }
    v[i1]=max(v[l1[i1]],v[r1[i1]]);
    w[i1]=max(w[l1[i1]],w[r1[i1]]);
}

void build(int i, int l, int r)
{
    v[i]=0;
    if (l==r) return;
    int mid=(l+r)/2;
    kol++;
    l1[i]=kol;
    kol++;
    r1[i]=kol;
    build(l1[i],l,mid);
    build(r1[i],mid+1,r);
}

pair<int,int> maxi(int i, int l, int r, int tl, int tr)
{
    if (tl<=l&&r<=tr) return mp(v[i],w[i]);
    if (tl>r||l>tr) return mp(0,0);
    int mid=(l+r)/2;
    pair<int,int> p1=maxi(l1[i],l,mid,tl,tr),p2=maxi(r1[i],mid+1,r,tl,tr);
    return mp(max(p1.ff,p2.ff),max(p1.ss,p2.ss));
}

vector<pair<int,pair<int,int> > > ww;
int n;

inline bool good(int tl, int tr, int x, int h)
{
    int l=0,r=ww.size()-1;
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (ww[mid].ff<h) l=mid; else r=mid;
    }
    if (ww[l].ff>=h) r=l;
    if (ww[r].ff<h) r=r+1;
    pair<int,int> p=maxi(root[r],1,n,1,tl);
    if (p.ss>=tl+x-1) return true;
    p=maxi(root[r],1,n,tl,tr-x+1);
    if (p.ss>=tr) return true;
    if (p.ff>=x) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    int kk=0;
    vector<pair<int,int> > vv;
    vector<int> vs;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        vs.pb(a[i]);
    }
    sort(vs.begin(),vs.end());
    for (int i=0; i<vs.size(); i++)
        if (mt[vs[i]]==0)
    {
        kk++;
        mt[vs[i]]=kk;
        ans[kk]=vs[i];
    }
    for (int i=1; i<=n; i++)
    {
        a[i]=mt[a[i]];
        vv.pb(mp(a[i],i));
    }
    sort(vv.begin(),vv.end());
    for (int i=vv.size()-1; i>=0; i--)
    {
        int l=vv[i].ss;
        if (gl[l-1]==0&&gl[l+1]==0)
        {
            gl[l]=l;
            sz[l]=1;
            ww.pb(mp(vv[i].ff,mp(l,l)));
        } else
        if (gl[l-1]==0)
        {
            int x=glava(l+1);
            gl[l]=x;
            sz[x]++;
            ww.pb(mp(vv[i].ff,mp(l,l+sz[x]-1)));
        } else
        if (gl[l+1]==0)
        {
            int x=glava(l-1);
            gl[l]=x;
            sz[x]++;
            ww.pb(mp(vv[i].ff,mp(l-sz[x]+1,l)));
        } else
        {
            //cout<<l-1<<" "<<l+1<<" - "<<gl[l-1]<<" "<<gl[l+1]<<endl;
            int x=glava(l-1);
            int y=glava(l+1);
            gl[x]=l;
            gl[y]=l;
            gl[l]=l;
            sz[l]=sz[x]+sz[y]+1;
            ww.pb(mp(vv[i].ff,mp(l-sz[x],l+sz[y])));
        }
    }
    sort(ww.begin(),ww.end());
    kol++;
    root[ww.size()]=kol;
    build(1,1,n);
    for (int i=ww.size()-1; i>=0; i--)
    {
        root[i]=root[i+1];
        pair<int,int> t=maxi(root[i+1],1,n,ww[i].ss.ff,ww[i].ss.ff);
        if (t.ss<ww[i].ss.ss)
        {
            kol++;
            root[i]=kol;
            update(root[i],root[i+1],1,n,ww[i].ss.ff,ww[i].ss.ss);
        }
    }
    int q;
    cin>>q;
    for (int i=1; i<=q; i++)
    {
        int tl,tr,x;
        cin>>tl>>tr>>x;
        int l=1,r=kk;
        while (r-l>1)
        {
            int mid=(l+r)/2;
            if (good(tl,tr,x,mid)) l=mid; else r=mid;
        }
        if (good(tl,tr,x,r)) l=r;
        cout<<ans[l]<<"\n";
    }
}