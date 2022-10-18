#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define ll long long
#define mp make_pair

const int N = 1e6 + 11;
const ll MOD0 = 1e9 + 7;
const ll P0 = 37;
const ll MOD1 = 1e9 + 9;
const ll P1 = 49;


ll a[N],b[N];
ll h1[2][N],h2[2][N],s[2][N];
ll m,n;
map<int,bool> ans;

int getnext(int pos)
{
    if (pos>a[n]) return 1e9;
    int l=1,r=n;
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (a[mid]>=pos) r=mid; else l=mid;
    }
    if (a[l]>=pos) return l;
    return r;
}

int getprev(int pos)
{
    if (pos<a[1]) return -1e9;
    int l=1,r=n;
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (a[mid]<=pos) l=mid; else r=mid;
    }
    if (a[r]<=pos) return r;
    return l;
}

bool good0(int l, int r)
{
    ll hash1=h1[0][r]-h1[0][l-1]+MOD0;
    hash1*=s[0][n-r];
    hash1%=MOD0;
    ll hash2=h2[0][l]-h2[0][r+1]+MOD0;
    hash2*=s[0][l];
    hash2%=MOD0;
    if (hash1==hash2) return true;
    return false;
}

bool good1(int l, int r)
{
    ll hash1=h1[1][r]-h1[1][l-1]+MOD1;
    hash1*=s[1][n-r];
    hash1%=MOD1;
    ll hash2=h2[1][l]-h2[1][r+1]+MOD1;
    hash2*=s[1][l];
    hash2%=MOD1;
    if (hash1==hash2) return true;
    return false;
}

bool good(ll x, ll y)
{
    if (x>y) return true;
    if (y<a[1]) return true;
    int l=getnext(x),r=getprev(y);
    if (l>r) return true;
    if (a[l]-x!=y-a[r]) return false;
    if (l==r) return true;
    if (good1(l,r-1)&&good0(l,r-1)) return true;
    return false;
}

bool good(ll p)
{
    if (ans[p]) return false;
    ans[p]=1;
    if (good(0,p)&&good(p+1,m-1)) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1; i<n; i++)
        b[i]=a[i+1]-a[i];
    s[0][0]=1;
    s[1][0]=1;
    for (int i=1; i<=n*2; i++)
    {
        s[0][i]=(s[0][i-1]*P0)%MOD0;
        s[1][i]=(s[1][i-1]*P1)%MOD1;
    }
    for (int i=1; i<n; i++)
    {
        h1[0][i]=(h1[0][i-1]+b[i]*s[0][i])%MOD0;
        h1[1][i]=(h1[1][i-1]+b[i]*s[1][i])%MOD1;
    }
    for (int i=n-1; i>=1; i--)
    {
        h2[0][i]=(h2[0][i+1]+b[i]*s[0][n-i])%MOD0;
        h2[1][i]=(h2[1][i+1]+b[i]*s[1][n-i])%MOD1;
    }

    vector<int> vv;
    for (int i=1; i<=n; i++)
    {
        ll x=(a[1]+a[i])%m;
        if (good(x)) vv.pb(x);
    }
    sort(vv.begin(),vv.end());
    cout<<vv.size()<<endl;
    for (int j=0; j<vv.size(); j++)
        cout<<vv[j]<<" ";
}