#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

const int N = 4e5 + 11;

ll a[N],s[N];
map<ll,int> mt;
int v[N*4];

void update(int i, int l, int r, int x, int t)
{
    if (l==r) {v[i]+=t; return;}
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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie();
    int n;
    ll t;
    cin>>n>>t;
    vector<ll> vv;
    vv.pb(0);
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
        vv.pb(s[i]);
        vv.pb(s[i]-t+1);
    }
    sort(vv.begin(),vv.end());
    int kk=0;
    for (int j=0; j<vv.size(); j++)
    {
        if (mt[vv[j]]==0)
        {
            kk++;
            mt[vv[j]]=kk;
        }
    }
    update(1,1,kk,mt[0],1);
    ll ans=0;
    for (int i=1; i<=n; i++)
    {
        ans+=1ll*get(1,1,kk,mt[s[i]-t+1],kk);
        update(1,1,kk,mt[s[i]],1);
    }
    cout<<ans<<"\n";
}