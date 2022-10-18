#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ld long double

const int N = 2e5 + 11;
const int MAX = -2e18;

ll t[N];
ll a[N],b[N];
set<int> poss;
ll w[N*4],v[N*4];
ll s1[N],s[N];

int nx(int x)
{
    auto it=poss.upper_bound(x);
    return *it;
}

void build(int i, int l, int r)
{
    w[i]=MAX;
    if (l==r) {v[i]=a[l]; return;}
    int mid=(l+r)/2;
    build(i+i,l,mid);
    build(i+i+1,mid+1,r);
    v[i]=v[i+i]+v[i+i+1];
}

ll get(int l, int r)
{
    ///cout<<"get "<<l<<".."<<r<<endl;
    int k=r-l+1;
    ///cout<<"k = "<<k<<endl;
    ll ans=(s[r-1]-s[l-1])*1ll*k;
    ///cout<<"1. ans = "<<ans<<endl;
    ll p=s1[r-1]-s1[l-1];
    ///cout<<"2. p = "<<p<<endl;
    p-=(l-1)*1ll*(s[r-1]-s[l-1]);
    ///cout<<"3. p = "<<p<<endl;
    ans-=p;
    ///cout<<"4. ans = "<<p<<endl;
    return ans;
}

void push(int i, int l, int r, int mid)
{
    if (w[i]==MAX) return;
    w[i*2]=w[i];
    w[i*2+1]=w[i]+s[mid]-s[l-1];
    v[i*2]=w[i*2]*1ll*(mid-l+1)+get(l,mid);
    v[i*2+1]=w[i*2+1]*1ll*(r-mid)+get(mid+1,r);
    w[i]=MAX;
}

void update(int i, int l, int r, int tl, int tr, ll x)
{
    if (tl<=l&&r<=tr)
    {
        ///cout<<l<<".."<<r<<" = "<<x<<"+."<<endl;
        w[i]=x+s[l-1]-s[tl-1];
        v[i]=get(l,r)+w[i]*1ll*(r-l+1);
        return;
    }
    if (tl>r||l>tr) return;
    int mid=(l+r)/2;
    push(i,l,r,mid);
    update(i*2,l,mid,tl,tr,x);
    update(i*2+1,mid+1,r,tl,tr,x);
    v[i]=v[i*2]+v[i*2+1];
}

ll get(int i, int l, int r, int tl, int tr)
{
    if (tl<=l&&r<=tr) return v[i];
    if (tl>r||l>tr) return 0;
    int mid=(l+r)/2;
    push(i,l,r,mid);
    return get(i*2,l,mid,tl,tr)+get(i*2+1,mid+1,r,tl,tr);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        poss.insert(i);
        t[i]=a[i];
    }
    poss.insert(n+1);
    for (int i=1; i<n; i++)
    {
        cin>>b[i];
        s[i]=s[i-1]+b[i];
        s1[i]=s1[i-1]+b[i]*1ll*i;
    }
    build(1,1,n);
    int q;
    cin>>q;
    for (int j=1; j<=q; j++)
    {
        char ch;
        cin>>ch;
        if (ch=='+')
        {
            int i;
            ll x;
            cin>>i>>x;
            ll d=get(1,1,n,i,i);
            poss.insert(i);
            t[i]=d+x;
            while (1)
            {
                int c=nx(i);
                if (c==n+1) break;
                if (t[c]>=t[i]+s[c-1]-s[i-1]) break;
                poss.erase(c);
            }
            int c=nx(i);
            ///cout<<i<<".."<<c-1<<" start is "<<t[i]<<endl;
            update(1,1,n,i,c-1,t[i]);
        } else
        {
            int l,r;
            cin>>l>>r;
            cout<<get(1,1,n,l,r)<<"\n";
        }
    }
}