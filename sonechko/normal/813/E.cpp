#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ld long double

const int N = 1e5 + 11;
const ll MOD = 1e18;
#define mod %MOD
int a[N],l1[N*40],r1[N*40],v[N*40],kol[N],nn1[N],last[N],p1[N];
int glava[N],m;
int kk;
void build(int i, int l, int r)
{
    if (l==r) return;
    int mid=(l+r)>>1;
    m++;
    l1[i]=m;
    build(m,l,mid);
    m++;
    r1[i]=m;
    build(m,mid+1,r);
}
void rec(int i1, int i2, int l, int r, int p, int d)
{
    if (l==r)
    {
        v[i2]=d;
        return;
    }
    l1[i2]=l1[i1];
    r1[i2]=r1[i1];
    int mid=(l+r)/2;
    if (p<=mid)
    {
        m++;
        l1[i2]=m;
        rec(l1[i1],l1[i2],l,mid,p,d);
    } else
    {
        m++;
        r1[i2]=m;
        rec(r1[i1],r1[i2],mid+1,r,p,d);
    }
    v[i2]=v[l1[i2]]+v[r1[i2]];
}
int get(int i, int l, int r, int tl, int tr)
{
    if (tl<=l&&r<=tr) return v[i];
    if (l>tr||r<tl) return 0;
    int mid=(l+r)/2;
    return get(l1[i],l,mid,tl,tr)+get(r1[i],mid+1,r,tl,tr);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n>>kk;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    glava[0]=1;
    m=1;
    build(1,1,n);
    for (int i=1; i<=n; i++)
    {
        nn1[last[a[i]]]=i;
        if (last[a[i]]==0) p1[a[i]]=i;
        int ks=glava[i-1];
        if (kol[a[i]]>=kk)
        {
        m++;
        ks=m;
        rec(glava[i-1],m,1,n,p1[a[i]],0);
        p1[a[i]]=nn1[p1[a[i]]];
        }
        last[a[i]]=i;
        kol[a[i]]++;
        m++;
        glava[i]=m;
        rec(ks,glava[i],1,n,i,1);
    }
    int q;
    cin>>q;
    int last=0;
    for (int i=1; i<=q; i++)
    {
        int x, y;
        cin>>x>>y;
        int l=(last+x)%n+1;
        int r=(last+y)%n+1;
        if (l>r) {swap(l,r);}
        last=get(glava[r],1,n,l,r);
        cout<<last<<"\n";
    }
}