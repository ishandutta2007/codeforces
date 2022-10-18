#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int N = 3e5 + 11;
const ll MOD = 998244353;

int a[N],b[N];
int k;

ll v[N*5],w1[N*5],w2[N*5];
ll dp[N];


inline void push(int i, int l, int r)
{
    v[i+i]=(v[i+i]*w1[i]+MOD)%MOD;
    v[i+i+1]=(v[i+i+1]*w1[i]+MOD)%MOD;
    w1[i+i]=(w1[i+i]*w1[i]+MOD)%MOD;
    w1[i+i+1]=(w1[i+i+1]*w1[i]+MOD)%MOD;
    w2[i+i]=(w2[i+i]*w1[i]+MOD)%MOD;
    w2[i+i+1]=(w2[i+i+1]*w1[i]+MOD)%MOD;
    w1[i]=1;
    int mid=(l+r)>>1;
    v[i+i]=(v[i+i]+w2[i]*1ll*(mid-l+1)+MOD)%MOD;
    v[i+i+1]=(v[i+i+1]+w2[i]*1ll*(r-mid)+MOD)%MOD;
    w2[i+i]=(w2[i+i]+w2[i])%MOD;
    w2[i+i+1]=(w2[i+i+1]+w2[i])%MOD;
    w2[i]=0;
}

inline void build(int i, int l, int r)
{
    if (l==r) {v[i]=dp[l]; w1[i]=1; w2[i]=0; return;}
    w1[i]=1;
    w2[i]=0;
    int mid=(l+r)>>1;
    build(i+i,l,mid);
    build(i+i+1,mid+1,r);
    v[i]=(v[i+i]+v[i+i+1])%MOD;
}

inline void mn(ll x)
{
    push(1,1,k);
    w1[1]=(x+MOD)%MOD;
    v[1]=(v[1]*x+MOD)%MOD;
}

inline void sum(ll x)
{
    push(1,1,k);
    w2[1]=(w2[1]+x+MOD)%MOD;
    v[1]=(v[1]+x*1ll*k+MOD)%MOD;
}

inline void update(int i, int l, int r, int x, ll t)
{
    push(i,l,r);
    if (l==r) {w2[i]=(w2[i]+t+MOD)%MOD; v[i]=(v[i]+t+MOD)%MOD; return;}
    int mid=(l+r)>>1;
    if (x<=mid) update(i+i,l,mid,x,t); else update(i+i+1,mid+1,r,x,t);
    v[i]=(v[i+i]+v[i+i+1])%MOD;
}

inline ll get(int i, int l, int r, int x)
{
    push(i,l,r);
    if (l==r) return v[i];
    int mid=(l+r)>>1;
    if (x<=mid) return get(i+i,l,mid,x);
    else return get(i+i+1,mid+1,r,x);
}

int n,m;

ll get()
{
    /**
    cout<<n<<endl;
    for (int i=1; i<=n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    **/
    for (int i=1; i<=N*4-10; i++)
    {
        w1[i]=0;
        w2[i]=0;
        v[i]=0;
    }
    for (int i=1; i<=N-10; i++)
    {
        dp[i]=0;
    }

    if (n==0) {return 1;}

    for (int i=1; i<=k; i++)
        dp[i]=0;
    if (a[1]==-1)
    {
        for (int i=1; i<=k; i++)
            dp[i]=1;
    } else dp[a[1]]=1;
    build(1,1,k);


    for (int i=2; i<=n; i++)
    if (a[i]==-1)
    {
        ll t=v[1];
        ///cout<<"mn -1"<<endl;
        ///cout<<"+ "<<t<<endl;
        mn(-1);
        sum(t);
    } else
    if (a[i]==a[i-1]) {return 0;} else
    {
        ///cout<<"get "<<a[i]<<" = "<<get(1,1,k,a[i])<<endl;
        ///cout<<"sum is "<<v[1]<<endl;
        ll t=(v[1]-get(1,1,k,a[i])+MOD)%MOD;
        mn(0);
        ///cout<<"mn 0 "<<endl;
        ///cout<<a[i]<<" +="<<t<<endl;
        update(1,1,k,a[i],t);
    }
    ///cout<<"!"<<v[1]<<endl;
    return v[1];
}

ll res;

void dfs(int l)
{
    if (l==n+1)
    {
        res++;
        return;
    }
    if (a[l]!=-1)
    {
        if (a[l-1]==a[l]) return;
        dfs(l+1);
    } else
    {
        for (int i=1; i<=k; i++)
            if (i!=a[l-1])
        {
            a[l]=i;
            dfs(l+1);
        }
        a[l]=-1;
    }
}

ll gets()
{
    res=0;
    dfs(1);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int nn;
    cin>>nn>>k;
    n=0;
    m=0;
    for (int i=1; i<=nn; i++)
    if (i%2==0) {n++; cin>>a[n];} else {m++; cin>>b[m];}
    ll ans1=get();
    n=m;
    for (int i=1; i<=n; i++)
        a[i]=b[i];
    ll ans2=get();
    cout<<(ans1*ans2)%MOD<<endl;

    /**
    cin>>n>>k;
    while (1)
    {
        for (int i=1; i<=n; i++)
        {
            a[i]=(rand()%(k+1));
            if (a[i]==0) a[i]=-1;
        }
        int p1=get();
        int p2=gets();
        if (p1!=p2)
        {
            for (int i=1; i<=n; i++)
                cout<<a[i]<<" ";
            cout<<endl;
            cout<<get()<<" "<<gets()<<endl;
            return 0;
        }
        cout<<"+"<<endl;
    }
    **/
}