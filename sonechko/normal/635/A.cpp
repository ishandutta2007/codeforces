#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, sizeof(x), y)
#define sqr(a) ((a) * (a))
#define ll long long
#define endl "\n"
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define f first
#define mp make_pair

int main()
{
    int n,m,p,k, ans=0;
    cin>>n>>m>>p>>k;
    int a[n+1][m+1];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        a[i][j]=0;
    for (int i=1; i<=p; i++)
    {
        int l,r;
        cin>>l>>r;
        a[l][r]=1;
    }
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+a[i][j];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        for (int l=i; l<=n; l++)
        for (int r=j; r<=m; r++)
    {
        int t=a[l][r]-a[i-1][r]-a[l][j-1]+a[i-1][j-1];
        if (t>=k) ans++;
    }
    cout<<ans<<endl;
}