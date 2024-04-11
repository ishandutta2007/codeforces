#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 3e5 + 11;

int a[N];
int root[N],l1[N*30],r1[N*30],t2[N*30];
int dp[N];
int t[N];
int n;
int k;

void build(int i, int l, int r)
{
    t2[i]=0;
    if (l==r) return;
    k++;
    l1[i]=k;
    k++;
    r1[i]=k;
    int mid=(l+r)/2;
    build(l1[i],l,mid);
    build(r1[i],mid+1,r);
}



int get(int i, int l, int r, int p)
{
    if (l==r) return t2[i];
    int mid=(l+r)/2;
    if (p<=mid) return get(l1[i],l,mid,p); else
        return get(r1[i],mid+1,r,p);
}

void update(int i1, int i2, int l, int r, int p, int d)
{
    if (l==r)
    {
        t2[i1]=d;
        return;
    }
    int mid=(l+r)/2;
    if (p<=mid)
    {
        k++;
        l1[i1]=k;
        r1[i1]=r1[i2];
        update(l1[i1],l1[i2],l,mid,p,d);
    } else
    {
        l1[i1]=l1[i2];
        k++;
        r1[i1]=k;
        update(r1[i1],r1[i2],mid+1,r,p,d);
    }
}

void up()
{
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    k=0;
    root[n+1]=0;
    build(0,1,n);
    t[n+1]=n+1;
    dp[n+1]=0;
    ll ans=0;
    for (int i=n; i>=1; i--)
    {
        t[i]=get(root[i+1],1,n,a[i]);
        k++;
        root[i]=k;
        if (t[i]==0) update(root[i],root[n+1],1,n,a[i],i);
                else update(root[i],root[t[i]+1],1,n,a[i],i);

        if (t[i]==0) dp[i]=0;
                else dp[i]=dp[t[i]+1]+1;

        ans+=1ll*dp[i];
        ///cout<<i<<": "<<t[i]<<" "<<dp[i]<<endl;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    while (q--)
        up();
}
/**
1   2 3 4 5 6 7 8 9
3   1 2 2 1 6 6 3 3
8   5 4 - - 7 - 9 -
3-1
3-9
**/