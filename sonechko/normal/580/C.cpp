#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 100005;
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
int n,m,sz,ans,next[N*2],last[N*2],b[N*2];
int a[N],use[N];
void dfs(int l, int r)
{
    //cout<<l<<" "<<r<<endl;
    if (r>m) return;
    int i=last[l],p=0;
    use[l]=1;
    while (i>0)
    {
        int to=b[i];
        if (use[to]==0)
    {
        p=1;
        if (a[to]==0) dfs(to,0); else
            dfs(to,a[to]+r);
    }
        i=next[i];
    }
    if (p==0) ans++;
}
void update(int l, int r)
{
    sz++;
    b[sz]=r;
    next[sz]=last[l];
    last[l]=sz;
}
int main()
{
    sync;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    cin>>a[i];
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        update(l,r);
        update(r,l);
    }
    dfs(1,a[1]);
    cout<<ans<<endl;
}