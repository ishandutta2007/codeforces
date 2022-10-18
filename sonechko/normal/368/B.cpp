#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 100004;
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
int n,m,a[N],b[N],ans[N];
int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    ans[n]=1;
    b[a[n]]=1;
    for (int i=n-1; i>=1; i--)
        if (b[a[i]]==1) ans[i]=ans[i+1]; else
    {
        ans[i]=ans[i+1]+1;
        b[a[i]]=1;
    }
    for (int i=1; i<=m; i++)
    {
        int l;
        cin>>l;
        cout<<ans[l]<<endl;
    }
}