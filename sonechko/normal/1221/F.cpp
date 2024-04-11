#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long

const int N = 1e6 + 11;

ll a[N],b[N],c[N],d[N];
int kk;
map<int,int> mt;
vector<int> vv[N];
ll v[N*4],w[N*4],ww[N*4];

void build(int i, int l, int r)
{
    ww[i]=l;
    v[i]=0;
    if (l==r) return;
    int mid=(l+r)/2;
    build(i+i,l,mid);
    build(i+i+1,mid+1,r);
}

void push(int i)
{
    v[i+i]+=w[i];
    v[i+i+1]+=w[i];
    w[i+i]+=w[i];
    w[i+i+1]+=w[i];
    w[i]=0;
}

void update(int i, int l, int r, int tl, int tr, ll k)
{
    if (tl<=l&&r<=tr)
    {
        v[i]+=k;
        w[i]+=k;
        return;
    }
    if (tl>r||l>tr) return;
    int mid=(l+r)/2;
    push(i);
    update(i+i,l,mid,tl,tr,k);
    update(i+i+1,mid+1,r,tl,tr,k);
    v[i]=max(v[i+i],v[i+i+1]);
    if (v[i+i]==v[i]) ww[i]=ww[i+i]; else ww[i]=ww[i+i+1];
}



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<int> v1,vs;
    for (int i=1; i<=n; i++)
    {
        int xx,yy,cc;
        cin>>xx>>yy>>cc;
        v1.pb(min(xx,yy));
        a[i]=min(xx,yy);
        b[i]=max(xx,yy);
        vs.pb(xx);
        vs.pb(yy);
        c[i]=cc;
    }
    sort(v1.begin(),v1.end());
    sort(vs.begin(),vs.end());
    for (int j=0; j<vs.size(); j++)
        if (mt[vs[j]]==0)
        {
            kk++;
            mt[vs[j]]=kk;
            d[kk]=vs[j];
        }
    build(1,1,kk);
    for (int i=1; i<=kk; i++)
    {
        update(1,1,kk,i,i,-d[i]);
    }
    for (int i=1; i<=n; i++)
    {
        update(1,1,kk,mt[b[i]],kk,c[i]);
        vv[mt[a[i]]].pb(i);
    }
    ll ans=0,p1=v1.back()+1,p2=v1.back()+1;
    int ps=0;
    for (int i=0; i<v1.size(); i++)
        if (i==0||v1[i]!=v1[i-1])
    {
        int pos=mt[v1[i]];
        while (ps+1<pos)
        {
            ps++;
            update(1,1,kk,ps,ps,-2e18);
        }
        if (v[1]+1ll*v1[i]>ans)
        {
            ///cout<<v1[i]<<": "<<v[1]<<" + "<<v1[i]<<"  "<<d[ww[1]]<<endl;
            ans=v[1]+1ll*v1[i];
            p1=v1[i];
            p2=d[ww[1]];
        }
        while (ps+1<=pos)
        {
            ps++;
            update(1,1,kk,ps,ps,-2e18);
        }
            for (int j=0; j<vv[pos].size(); j++)
            {
                int l=vv[pos][j];
                update(1,1,kk,mt[b[l]],kk,-c[l]);
            }
    }
    cout<<ans<<endl;
    cout<<p1<<" "<<p1<<" "<<p2<<" "<<p2<<endl;
}
/**
B.B.B.......
..WBW.......
BW.WB.......
.B.B........
B.B.........
............
............
............
............
............
............
............

(a,a)
min(xi,y1)>=a
`


**/