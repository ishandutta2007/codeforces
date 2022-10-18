#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 4e5 + 11;
const int MOD = 1e9 + 7;
const int P = 31;

int a[N],b[N],c[N],d[N];
map<int,int> mt;
ll v[N*4],st[N];
ll d1[N],d2[N];



void build(int i, int l, int r)
{
    if (l==r) {v[i]=0; return;}
    v[i]=0;
    int mid=(l+r)/2;
    build(i+i,l,mid);
    build(i+i+1,mid+1,r);
}

void update(int i, int l, int r, int x, int t)
{
    if (l==r)
    {
        v[i]=(v[i]+st[t])%MOD;
        return;
    }
    int mid=(l+r)/2;
    if (x<=mid) update(i+i,l,mid,x,t); else update(i+i+1,mid+1,r,x,t);
    v[i]=(v[i+i]+v[i+i+1])%MOD;
}

int get(int i, int l, int r, int tl, int tr)
{
    if (tl<=l&&r<=tr) return v[i];
    if (tl>r||l>tr) return 0;
    int mid=(l+r)/2;
    return (get(i+i,l,mid,tl,tr)+get(i+i+1,mid+1,r,tl,tr))%MOD;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<int> vvv;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i]>>b[i]>>c[i]>>d[i];
        vvv.pb(a[i]);
        vvv.pb(b[i]);
        vvv.pb(c[i]);
        vvv.pb(d[i]);
    }
    int kk=0;
    sort(vvv.begin(),vvv.end());
    for (int i=0; i<vvv.size(); i++)
        if (mt[vvv[i]]==0)
    {
        kk++;
        mt[vvv[i]]=kk;
    }
    vector<pair<int,pair<int,int> > > vv;
    for (int i=1; i<=n; i++)
    {
        a[i]=mt[a[i]];
        b[i]=mt[b[i]];
        c[i]=mt[c[i]];
        d[i]=mt[d[i]];
        vv.pb(mp(a[i],mp(b[i],i)));
    }
    st[0]=1;
    for (int j=1; j<=n; j++)
        st[j]=(st[j-1]*1ll*P)%MOD;
    sort(vv.begin(),vv.end());
    build(1,1,kk);
    for (int i=0; i<vv.size(); i++)
    {
        int aa=vv[i].ff,bb=vv[i].ss.ff,num=vv[i].ss.ss;
        d1[num]=(d1[num]+get(1,1,kk,aa,kk))%MOD;
        update(1,1,kk,bb,num);
    }
    build(1,1,kk);
    for (int i=vv.size()-1; i>=0; i--)
    {
        int aa=vv[i].ff,bb=vv[i].ss.ff,num=vv[i].ss.ss;
        d1[num]=(d1[num]+get(1,1,kk,1,bb))%MOD;
        update(1,1,kk,aa,num);
    }

    vv.clear();
    for (int i=1; i<=n; i++)
        vv.pb(mp(c[i],mp(d[i],i)));
    sort(vv.begin(),vv.end());
    build(1,1,kk);
    for (int i=0; i<vv.size(); i++)
    {
        int aa=vv[i].ff,bb=vv[i].ss.ff,num=vv[i].ss.ss;
        d2[num]=(d2[num]+get(1,1,kk,aa,kk))%MOD;
        update(1,1,kk,bb,num);
    }
    build(1,1,kk);
    for (int i=vv.size()-1; i>=0; i--)
    {
        int aa=vv[i].ff,bb=vv[i].ss.ff,num=vv[i].ss.ss;
        d2[num]=(d2[num]+get(1,1,kk,1,bb))%MOD;
        update(1,1,kk,aa,num);
    }
    //for (int i=1; i<=n; i++)
    //    cout<<d1[i]<<" : "<<d2[i]<<endl;
    for (int i=1; i<=n; i++)
        if (d1[i]!=d2[i]) return cout<<"NO", 0;
    cout<<"YES";
}
/**
i j
ai bi
aj bj


1) i<j&&bi>=aj
2) i>j&&ai<=bi


**/