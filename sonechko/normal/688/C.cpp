#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 200001;
const int M = 10;
const string st2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string s1 = "abcdefghijklmnopqrstuvwxyz";
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define filestxt freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, sizeof(x), y)
#define sqr(a) ((a) * (a))
//#define endl "\n"
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define ll long long
#define f first
#define mp make_pair
#define y1 dbfuebfwkjNBSciwbe
#define time zdfheajbrkjasghduw
int use[N],sz,last[N],next[N],b[N],ans;
void dfs(int v, int p)
{
    if (ans==-1) return;
    use[v]=p;
    int i=last[v];
    while (i>0)
    {
        int to=b[i];
        if (use[to]==p)
        {
            ans=-1;
            return;
        } else
        if (use[to]==0)
        {
            dfs(to,3-p);
        }
        i=next[i];
    }
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
    #ifdef LOCAL
    filestxt;
    #else

    #endif // LOCAL
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        update(l,r);
        update(r,l);
    }
    for (int i=1; i<=n; i++)
    if (use[i]==0) {dfs(i,1);}
    if (ans==-1) {cout<<ans<<endl; return 0;}
    int k1=0,k2=0;
    for (int i=1; i<=n; i++)
    {
        if (use[i]==1) k1++;
    }
    cout<<k1<<endl;
    for (int i=1; i<=n; i++)
        if (use[i]==1) cout<<i<<" ";
    cout<<endl;
    cout<<n-k1<<endl;
    for (int i=1; i<=n; i++)
        if (use[i]==2) cout<<i<<" ";
    cout<<endl;
}

/// wGFT4KZJ