#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

const int N = 1e5 + 11;

int v[N*60],l1[N*60],r1[N*60],kol,root[N],a[N];
vector<int> d[N];

void update(int i1, int i2, int l, int r, int x, int y)
{
    if (l==r) {v[i1]=y; return;}
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
    v[i1]=v[l1[i1]]+v[r1[i1]];
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

int get(int i, int l, int r, int kol)
{
    if (v[i]<=kol) return l;
    if (l==r) return r+1;
    int mid=(l+r)/2;
    if (v[r1[i]]<=kol) return get(l1[i],l,mid,kol-v[r1[i]]);
    return get(r1[i],mid+1,r,kol);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    kol++;
    root[0]=kol;
    build(1,1,n);
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        kol++;
        root[i]=kol;
        update(root[i],root[i-1],1,n,i,1);
        //cout<<i<<" - "<<1<<endl;
        d[a[i]].pb(i);
        if (d[a[i]].size()>1)
        {
            kol++;
            int p=root[i];
            root[i]=kol;
            update(root[i],p,1,n,d[a[i]][d[a[i]].size()-2],0);
            //cout<<d[a[i]].back()<<" - "<<0<<endl;
        }
    }
    for (int i=1; i<=n; i++)
    {
        int pos=n;
        int ans=0;
        //cout<<i<<": "<<endl;
        while (pos>=1)
        {
            ans++;
            int p=get(root[pos],1,n,i);
            pos=p-1;
        }
        cout<<ans<<" ";
    }
    cout<<endl;
}