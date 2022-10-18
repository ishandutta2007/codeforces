#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define ll long long
#define mp make_pair

const int N = 5e5 + 11;
const int MOD = 1e9 + 7;
#define mod %MOD



map<int,int> mt;
vector<int> v[N];
int kol;
pair<int,pair<int,int> > a[N];
int x[N],y[N],d[N],num[N],tt[N],last[N];
int w[N*4];

void update(int i, int l, int r, int x, int t)
{
    if (l==r) {w[i]=t; return;}
    int mid=(l+r)/2;
    if (x<=mid) update(i*2,l,mid,x,t); else update(i*2+1,mid+1,r,x,t);
    w[i]=w[i*2]+w[i*2+1];
}

int get(int i, int l, int r, int tl, int tr)
{
    if (tl<=l&&r<=tr) return w[i];
    if (tl>r||l>tr) return 0;
    int mid=(l+r)/2;
    return get(i*2,l,mid,tl,tr)+get(i*2+1,mid+1,r,tl,tr);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i].ff>>a[i].ss.ff>>a[i].ss.ss;
    }
    sort(a+1,a+n+1);
    for (int i=1; i<=n; i++)
    {
        x[i]=a[i].ff;
        y[i]=a[i].ss.ff;
        d[i]=a[i].ss.ss;
        if (mt[d[i]]==0) {kol++; mt[d[i]]=kol;}
        v[mt[d[i]]].pb(i);
    }
    int c=0;
    for (int i=1; i<=kol; i++)
    {
        for (int j=0; j<v[i].size(); j++)
        {
            c++;
            tt[c]=v[i][j];
            num[v[i][j]]=c;
        }
        last[i]=c;
    }
    set<pair<int,int> > st;
    ll ans=0;
    for (int i=1; i<=n; i++)
    {
        while (st.size()>0)
        {
            pair<int,int> p=*st.begin();
            if (p.ff<x[i])
            {
                st.erase(p);
                update(1,1,n,num[p.ss],0);
            } else break;
        }
        for (int s=d[i]-m; s<=d[i]+m; s++)
            if (mt[s]!=0)
        {
            int j=mt[s];
            int l=0,r=v[j].size()-1;
            while (r-l>1)
            {
                int mid=(l+r)/2;
                if (x[v[j][mid]]<x[i]-y[i]) l=mid; else r=mid;
            }
            if (x[v[j][l]]>=x[i]-y[i]) ans+=1ll*get(1,1,n,num[v[j][l]],last[j]); else
            if (x[v[j][r]]>=x[i]-y[i]) ans+=1ll*get(1,1,n,num[v[j][r]],last[j]);
        }
        st.insert(mp(x[i]+y[i],i));
        update(1,1,n,num[i],1);
    }
    cout<<ans<<endl;
}