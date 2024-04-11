#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 300005;
const int M = 10;
const string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, sizeof(x), y)
#define sqr(a) ((a) * (a))
#define endl "\n"
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define ll long long
#define f first
#define mp make_pair
#define next ljjdfienf
int a[N],b[N],m,n;
bool good(int k)
{
    for (int i=1; i<=n-k+1; i++)
    if (b[i+k-1]-b[i-1]<=m) return true;
    return false;
}
int main()
{
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        {
            cin>>a[i];
            b[i]=b[i-1]+(1-a[i]);
        }
    int l=0;
    int r=n;
    while (r-l>1)
    {
        int k=(l+r)/2;
        if (good(k)) l=k; else r=k;
    }
    int ans=0;
    if (good(r)) ans=r; else ans=l;
    cout<<ans<<endl;
    for (int i=1; i<=n-ans+1; i++)
        if (b[i+ans-1]-b[i-1]<=m)
    {
        for (int j=1; j<=n; j++)
            if (j>=i&&j<=i+ans-1)
            cout<<1<<" "; else
            cout<<a[j]<<" ";

        cout<<endl;
        return 0;
    }
}