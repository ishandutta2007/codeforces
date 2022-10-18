#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define ll long long
#define mp make_pair

const int N = 3e5 + 11;

ll a[N];
ll v1[N*4],v2[N*4];
int n;

void update(int i, int l, int r, int x, ll t1, ll t2)
{
    if (l==r) {v1[i]=t1; v2[i]=t2; return;}
    int mid=(l+r)/2;
    if (x<=mid) update(i*2,l,mid,x,t1,t2); else update(i*2+1,mid+1,r,x,t1,t2);
    v1[i]=v1[i*2]+v1[i*2+1];
    v2[i]=v2[i*2]+v2[i*2+1];
}

pair<ll,ll> sum(int i, int l, int r, int tl, int tr)
{
    if (tl<=l&&r<=tr) return mp(v1[i],v2[i]);
    if (tl>r||l>tr) return mp(0ll,0ll);
    int mid=(l+r)/2;
    pair<ll,ll> p1=sum(i*2,l,mid,tl,tr),p2=sum(i*2+1,mid+1,r,tl,tr);
    return mp(p1.ff+p2.ff,p1.ss+p2.ss);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>n>>t;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        update(1,1,n,i,a[i],1);
    }
    ll x=t;
    ll kol=n;
    ll pos=1;
    ll ans=0;
    while (1)
    {
        if (kol==0) break;
        ll s=v1[1];
        ll pp=x/s;
        x-=pp*s;
        pp*=kol;
        ans+=pp;
        pair<ll,ll> p=sum(1,1,n,pos,n);
        if (p.ff<=x)
        {
            x-=p.ff;
            ans+=p.ss;
            pos=1;
        } else
        {
            int l=pos,r=n;
            while (r-l>1)
            {
                int mid=(l+r)/2;
                if (sum(1,1,n,pos,mid).ff<=x) l=mid; else r=mid;
            }
            int rr;
            if (sum(1,1,n,pos,r).ff<=x) rr=r+1; else
            if (sum(1,1,n,pos,l).ff<=x) rr=l+1; else rr=pos;
            if (rr!=pos) {x-=sum(1,1,n,pos,rr-1).ff; ans+=sum(1,1,n,pos,rr-1).ss;}
            update(1,1,n,rr,0,0);
            kol--;
            pos=rr;
        }
    }
    cout<<ans<<endl;
}