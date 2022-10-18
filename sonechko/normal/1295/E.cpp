#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define pb push_back

const int N = 2e5 + 11;

int pos[N];
int p[N],a[N];
ll v[N*4],w[N*4];

void push(int i)
{
    v[i+i]+=w[i];
    w[i+i]+=w[i];
    v[i+i+1]+=w[i];
    w[i+i+1]+=w[i];
    w[i]=0;
}

void update(int i, int l, int r, int tl, int tr, ll p)
{
    if (tl<=l&&r<=tr)
    {
        v[i]+=p;
        w[i]+=p;
        return;
    }
    if (tl>r||l>tr) return;
    int mid=(l+r)/2;
    push(i);
    update(i+i,l,mid,tl,tr,p);
    update(i+i+1,mid+1,r,tl,tr,p);
    v[i]=min(v[i+i],v[i+i+1]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>p[i];
        pos[p[i]]=i;
    }
    for (int i=1; i<=n; i++)
        cin>>a[i];
    if (p[1]==1||p[n]==n) return cout<<0, 0;
    ll ans=2e9;
    for (int i=1; i<=n; i++)
        update(1,1,n-1,i,n,a[i]);
    ans=v[1];
    for (int x=1; x<=n; x++)
    {
        int c=pos[x];
        update(1,1,n-1,c,n,-a[c]);
        update(1,1,n-1,1,c-1,a[c]);
        ///cout<<x<<": "<<v[1]<<endl;
        ans=min(ans,v[1]);
    }
    cout<<ans<<"\n";
}