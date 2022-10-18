#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

map<int,int> mt;
int a[N],b[N],kk;
ll ans;
int v[N*4];

void update(int i, int l, int r, int x, int t)
{
    if (l==r) {v[i]=t; return;}
    int mid=(l+r)/2;
    if (x<=mid) update(i+i,l,mid,x,t); else update(i+i+1,mid+1,r,x,t);
    v[i]=v[i+i]+v[i+i+1];
}

int get(int i, int l, int r, int tl, int tr)
{
    if (tl<=l&&r<=tr) return v[i];
    if (tl>r||l>tr) return 0;
    int mid=(l+r)/2;
    return get(i+i,l,mid,tl,tr)+get(i+i+1,mid+1,r,tl,tr);
}

void up(vector<int> poss)
{
    vector<int> pos;
    sort(poss.begin(),poss.end());
    for (int j=0; j<poss.size(); j++)
        if (j==0||poss[j]!=poss[j-1]) pos.pb(poss[j]);
    vector<int> d;
    d.pb(get(1,1,kk,1,pos[0]-1)+1);
    for (int i=1; i<pos.size(); i++)
        d.pb(get(1,1,kk,pos[i-1]+1,pos[i]-1)+1);
    d.pb(get(1,1,kk,pos.back()+1,kk)+1);
    int sum=0;
    for (int j=0; j<d.size(); j++)
        sum+=d[j];
    for (int j=0; j<d.size()-1; j++)
    {
        sum-=d[j];
        ans+=sum*1ll*d[j];
    }
    for (int j=0; j<pos.size(); j++)
        update(1,1,kk,pos[j],1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int> > vv;
    vector<int> vs;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i]>>b[i];
        vv.pb(mp(b[i],i));
        vs.pb(a[i]);
    }
    sort(vv.begin(),vv.end());
    reverse(vv.begin(),vv.end());
    sort(vs.begin(),vs.end());
    for (int j=0; j<vs.size(); j++)
        if (j==0||vs[j]!=vs[j-1]) {kk++; mt[vs[j]]=kk;}
    for (int i=1; i<=n; i++)
        a[i]=mt[a[i]];
    vector<int> nn;
    for (int i=0; i<vv.size(); i++)
        if (i==0||vv[i].ff==vv[i-1].ff) nn.pb(a[vv[i].ss]); else
    {
        up(nn);
        nn.clear();
        nn.pb(a[vv[i].ss]);
    }
    up(nn);
    cout<<ans<<endl;
}