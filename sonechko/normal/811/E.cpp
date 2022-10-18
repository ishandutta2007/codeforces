#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 1e5 + 11;

int a[12][N];
int n,m;

struct ox
{
    int v1[11],v2[11];
    int l,r;
    int kol;
    int op;
};

ox v[N*4];
int d[N*20];

inline int gl(int l)
{
    if (l==d[l]) return l;
    return d[l]=gl(d[l]);
}

inline ox combine(ox i1, ox i2, int mid)
{
    ox i;
    i.l=i1.l;
    i.r=i2.r;
    i.op=0;
    i.kol=i1.kol+i2.kol;
    for (int j=1; j<=n; j++)
    {
        d[i1.v1[j]]=i1.v1[j];
        d[i1.v2[j]]=i1.v2[j];
        d[i2.v1[j]]=i2.v1[j];
        d[i2.v2[j]]=i2.v2[j];
    }
    for (int j=1; j<=n; j++)
        if (a[j][mid]==a[j][mid+1])
        {
            int l=i1.v2[j];
            int r=i2.v1[j];
            if (gl(l)!=gl(r))
            {
                d[gl(l)]=gl(r);
                i.kol--;
            }
        }
    for (int j=1; j<=n; j++)
    {
        i.v1[j]=(gl(i1.v1[j]));
        i.v2[j]=(gl(i2.v2[j]));
    }
    return i;
}

inline void build(int i, int l, int r)
{
    if (l==r)
    {
        v[i].l=l;
        v[i].r=r;
        v[i].op=1;
        v[i].kol=0;
        for (int ii=1; ii<=n; ii++)
        {
            if (ii>1&&a[ii][l]==a[ii-1][l]) v[i].v1[ii]=(v[i].v1[ii-1]); else
            {v[i].v1[ii]=((ii-1)*m+l); v[i].kol++;}
            v[i].v2[ii]=v[i].v1[ii];
        }
        ///cout<<l<<".."<<r<<" = "<<v[i].kol<<endl;
        return;
    }
    int mid=(l+r)/2;
    build(i+i,l,mid);
    build(i+i+1,mid+1,r);
    v[i]=combine(v[i+i],v[i+i+1],mid);
    ///cout<<l<<".."<<r<<" - "<<v[i].kol<<endl;
}

inline ox get(int i, int l, int r, int tl, int tr)
{
    if (tl<=l&&r<=tr) return v[i];
    if (tl>r||l>tr)
    {
        ox c;
        c.op=-1;
        return c;
    }
    int mid=(l+r)/2;
    ox p1=get(i+i,l,mid,tl,tr),p2=get(i+i+1,mid+1,r,tl,tr);
    if (p1.op==-1) return p2;
    if (p2.op==-1) return p1;
    return combine(p1,p2,mid);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>n>>m>>q;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    cin>>a[i][j];
    build(1,1,m);
    for (int j=1; j<=q; j++)
    {
        int l,r;
        cin>>l>>r;
        ox p=get(1,1,m,l,r);
        cout<<p.kol<<"\n";
    }

}