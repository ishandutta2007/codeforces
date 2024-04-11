#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 100001;
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
#define endl "\n"
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define ll long long
#define f first
#define mp make_pair
ll last[N],next[N],b[N],a[N],c[N],sz,ans;
void update(ll l, ll r, ll k)
{
    sz++;
    b[sz]=r;
    c[sz]=k;
    next[sz]=last[l];
    last[l]=sz;
}
void dfs(int v,ll sum, int type)
{
    if (a[v]<sum||type==1)
    {
        ans++;
        int i=last[v];
        while (i>0)
        {
            dfs(b[i],0,1);
            i=next[i];
        }
    } else
    {
        int i=last[v];
        while (i>0)
        {
            ll g=max(c[i],sum+c[i]);
            dfs(b[i],g,0);
            i=next[i];
        }
    }
}
int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=2; i<=n; i++)
    {
        ll l,h;
        cin>>l>>h;
        update(l,i,h);
    }
    dfs(1,0,0);
    cout<<ans<<endl;
}