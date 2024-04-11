#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 11;

pair<int,pair<int,int> > a[N*3];
int res[N],root[N*3];
int kk;
int l1[N*50],r1[N*50],p[N*50];

void build(int i, int l, int r)
{
    p[i]=2e9;
    if (l==r) return;
    kk++;
    l1[i]=kk;
    kk++;
    r1[i]=kk;
    int mid=(l+r)/2;
    build(l1[i],l,mid);
    build(r1[i],mid+1,r);
}

void build(int i1, int i2, int l, int r, int x, int t)
{
    if (l==r) {p[i1]=t; return;}
    int mid=(l+r)/2;
    if (x<=mid)
    {
        kk++;
        l1[i1]=kk;
        r1[i1]=r1[i2];
        build(l1[i1],l1[i2],l,mid,x,t);
    } else
    {
        kk++;
        l1[i1]=l1[i2];
        r1[i1]=kk;
        build(r1[i1],r1[i2],mid+1,r,x,t);
    }
    p[i1]=max(p[l1[i1]],p[r1[i1]]);
}

int maxx(int i, int l, int r, int tl, int tr)
{
    if (tl<=l&&r<=tr) return p[i];
    if (tl>r||l>tr) return -2e9;
    int mid=(l+r)/2;
    return max(maxx(l1[i],l,mid,tl,tr),maxx(r1[i],mid+1,r,tl,tr));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1; i<=k; i++)
    cin>>a[i].ff>>a[i].ss.ff>>a[i].ss.ss;
    sort(a+1,a+k+1);
    kk++;
    root[k+1]=kk;
    build(kk,1,n);
    for (int i=1; i<=n; i++)
        res[i]=2e9;
    for (int i=k; i>=1; i--)
    {
        //cout<<"! "<<a[i].ff<<" "<<a[i].ss.ff<<" "<<a[i].ss.ss<<endl;
        int num=a[i].ss.ss;
        if (res[num]>a[i].ss.ff)
        {
            res[num]=a[i].ss.ff;
            kk++;
            root[i]=kk;
            build(root[i],root[i+1],1,n,num,a[i].ss.ff);
        } else root[i]=root[i+1];
    }
    for (int i=1; i<=m; i++)
    {
        int aa,bb,x,y;
        cin>>aa>>bb>>x>>y;
        int l=1,r=k;
        while (r-l>1)
        {
            int mid=(l+r)/2;
            if (a[mid].ff>=x) r=mid; else l=mid;
        }
        if (a[l].ff>=x) r=l;
        if (a[r].ff>=x)
        {
            //cout<<"!! "<<r<<" "<<a[r].ff<<" "<<aa<<".."<<bb<<" = ";
            int d=maxx(root[r],1,n,aa,bb);
            //cout<<d<<endl;
            if (d<=y) cout<<"yes"<<endl; else cout<<"no"<<endl;
        } else cout<<"no"<<endl;
    }
}