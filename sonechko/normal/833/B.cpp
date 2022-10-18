#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define y1 skfn

const int N = 4e4 + 11;
const int MOD = 1e9 + 7;
#define mod %MOD

int n,k;
int dp[55][N],opt[55][N];
int pr[N],mt[N],a[N];
int ans;
int v[N*4],w[N*4];

void build(int i, int l, int r)
{
    v[i]=0;
    w[i]=0;
    if (l==r) return;
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
}

void push(int i)
{
    v[i*2]+=w[i];
    v[i*2+1]+=w[i];
    w[i*2]+=w[i];
    w[i*2+1]+=w[i];
    w[i]=0;
}

void update(int i, int l, int r, int tl, int tr, int x)
{
    if (tl<=l&&r<=tr) {v[i]+=x; w[i]+=x; return;}
    if (tl>r||l>tr) return;
    int mid=(l+r)/2;
    push(i);
    update(i*2,l,mid,tl,tr,x);
    update(i*2+1,mid+1,r,tl,tr,x);
    v[i]=max(v[i*2],v[i*2+1]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        pr[i]=mt[a[i]];
        mt[a[i]]=i;
    }
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        if (pr[i]==0) ans++;
        dp[1][i]=ans;
        //cout<<i<<" - "<<dp[1][i]<<endl;
    }
    for (int j=2; j<=k; j++)
    {
        build(1,1,n);
        update(1,1,n,j-1,j-1,dp[j-1][j-1]);
        //cout<<j-1<<" -> "<<dp[j-1][j-1]<<endl;
        for (int i=1; i<=n; i++)
            mt[i]=0;
        for (int i=j; i<=n; i++)
        {
            pr[i]=mt[a[i]];
            mt[a[i]]=i;
        }
        for (int i=j; i<=n; i++)
        {
            //cout<<i<<" - "<<pr[i]<<".."<<i-1<<"+="<<1<<endl;
            update(1,1,n,pr[i],i-1,1);
            //cout<<"max ans is "<<v[1]<<endl;
            dp[j][i]=v[1];
            //cout<<i<<".."<<i<<"+="<<dp[j-1][i]<<"(dp)"<<endl;
            update(1,1,n,i,i,dp[j-1][i]);
        }
        //cout<<"!!! ";
        //for (int i=1; i<=n; i++)
        //    cout<<dp[j][i]<<" ";
        //cout<<endl;
    }
    cout<<dp[k][n]<<endl;
}