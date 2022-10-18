#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int N = 2e5 + 11;

int n,m;
ll t;
int a[N];
ll v1[N*4],v2[N*4];

void build(int i, int l, int r)
{
    v1[i]=0;
    v2[i]=0;
    if (l==r) return;
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
}

void update(int i, int l, int r, int x, ll t)
{
    if (l==r) {v1[i]=1; v2[i]=t; return;}
    int mid=(l+r)/2;
    if (x<=mid) update(i*2,l,mid,x,t); else update(i*2+1,mid+1,r,x,t);
    v1[i]=v1[i*2]+v1[i*2+1];
    v2[i]=v2[i*2]+v2[i*2+1];
}

ll sum(int i, int l, int r, int tl, int tr)
{
    if (tl<=l&&r<=tr) return v2[i];
    if (tl>r||l>tr) return 0;
    int mid=(l+r)/2;
    return sum(i*2,l,mid,tl,tr)+sum(i*2+1,mid+1,r,tl,tr);
}

int find_num(int i, int l, int r, int x)
{
    if (v1[i]<x) return -1;
    if (l==r&&x==1) return l;
    if (l==r) return -1;
    int mid=(l+r)/2;
    if (v1[i*2]>=x) return find_num(i*2,l,mid,x);
    return find_num(i*2+1,mid+1,r,x-v1[i*2]);
}

bool good(int x, int y)
{
    int c=find_num(1,1,n,x*m),cc=find_num(1,1,n,x*m+y);
    if (x==0) c=0;
    //cout<<"? "<<x<<" "<<y<<" - "<<c<<" "<<cc<<"\n";
    if (cc==-1) return false;
    if (sum(1,1,n,1,c)*2ll+sum(1,1,n,c+1,cc)>t) return false;
    //cout<<"good!\n";
    return true;
}

void up()
{
    cin>>n>>m>>t;
    vector<int> vv;
    vector<pair<int,int> > v;
    int c=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        if (a[i]!=1) vv.pb(a[i]-1);
        v.pb(mp(a[i],i));
        c=max(c,a[i]);
    }
    vv.pb(min(c*1ll,t));
    sort(vv.begin(),vv.end());
    vv.erase(unique(vv.begin(),vv.end()),vv.end());
    sort(v.begin(),v.end());
    int pos=-1;
    build(1,1,n);
    int ans=0;
    int dd=1;
    for (int iii=0; iii<vv.size(); iii++)
    {
        int d=vv[iii];
        while (pos+1<v.size()&&v[pos+1].ff<=d)
        {
            pos++;
            update(1,1,n,v[pos].ss,v[pos].ff);
        }
        int l=1,r=n/m+1;
        while (r-l>1)
        {
            int mid=(l+r)/2;
            if (good(mid,0)) l=mid; else r=mid;
        }
        int kol;
        if (good(r,0)) kol=r; else
        if (good(l,0)) kol=l; else kol=0;
        l=1,r=m;
        while (r-l>1)
        {
            int mid=(l+r)/2;
            if (good(kol,mid)) l=mid; else r=mid;
        }
        int res=0;
        if (good(kol,r)) res=kol*m+r; else
        if (good(kol,l)) res=kol*m+l; else res=kol*m;
        //cout<<d<<" - "<<kol<<"*"<<m<<"+"<<res-kol*m<<"\n";
        if (res>ans) {ans=res; dd=d;}
    }
    //cout<<"ans is\n";
    cout<<ans<<" "<<dd<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ks;
    cin>>ks;
    while (ks--)
        up();
}