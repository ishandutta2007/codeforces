#include<bits/stdc++.h>
using namespace std;
const int N = 100
 + 11;
const long long MOD = 1e9 + 7;
#define mod %MOD
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ss second
#define ff first
#define ll long long
#define mp make_pair
#define endl "\n"
#define pb push_back
#define y1 ijdj
#define next lzk
#define ld long double
ll n,m,k,x,y;
ll a[N][N];
int main()
{
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif // LOCAL
    sync;
    cin>>n>>m>>k>>x>>y;
    ll p=k/m;
    ll l=0,r=p;
    while (r-l>1)
    {
        ll mid=(l+r)/2;
        if (p/mid>=(n+max((ll)0,n-2))&&mid*(n+max((ll)0,n-2))<=p) l=mid;
        else r=mid;
    }
    if (r*(n+max((ll)0,n-2))<=p) l=r;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    if (i==1||i==n) a[i][j]+=l; else a[i][j]+=l*2;
    k-=l*(n+max((ll)0,n-2))*m;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    if (k==0) break; else
    {
        a[i][j]++;
        k--;
    }
    for (int i=n-1; i>=1; i--)
    for (int j=1; j<=m; j++)
    if (k==0) break; else
    {
        a[i][j]++;
        k--;
    }
    ll amin=LONG_LONG_MAX,amax=0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
    {
        amin=min(amin,a[i][j]);
        amax=max(amax,a[i][j]);
    }
    cout<<amax<<" "<<amin<<" "<<a[x][y]<<endl;
}