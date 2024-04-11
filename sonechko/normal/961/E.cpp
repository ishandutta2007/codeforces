#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
const int MOD = 1e9 + 7;
#define mod %MOD

const int N = 2e5 + 11;

vector<int> v[N];
int w[N*4],a[N];

void update(int i, int l, int r, int x, int t)
{
    if (l==r) {w[i]=t; return;}
    int mid=(l+r)/2;
    if (x<=mid) update(i*2,l,mid,x,t); else update(i*2+1,mid+1,r,x,t);
    w[i]=w[i*2]+w[i*2+1];
}
int sum(int i, int l, int r, int tl, int tr)
{
    if (tl<=l&&r<=tr) return w[i];
    if (tl>r||l>tr) return 0;
    int mid=(l+r)/2;
    return sum(i*2,l,mid,tl,tr)+sum(i*2+1,mid+1,r,tl,tr);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        a[i]=min(a[i],n);
    }
    ll ans=0;
    for (int i=n; i>=1; i--)
    {
        int x=a[i];
        for (int j=0; j<v[i].size(); j++)
            update(1,1,n,v[i][j],1);
        if (x>=i) ans+=1ll*sum(1,1,n,i,x);
        if (x<i) v[x].pb(i); else update(1,1,n,i,1);
    }
    cout<<ans<<endl;
}