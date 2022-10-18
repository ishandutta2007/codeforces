#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 200000+10;
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
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define ll long long
#define f first
#define mp make_pair
#define y1 dbfuebfwkjNBSciwbe
#define time zdfheajbrkjasghduw
#define ull unsigned long long
#define randomize srand(time(NULL))
#define next ifhiuebf
#define last dkbffjrb
ll a[N],b[N],c[N],d[N],n,m,s,x,k;
pair<ll,ll> ff[N];
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    sync;
    #endif // LOCAL
    cin>>k>>n>>m>>x>>s;
    for (int i=1; i<=n; i++)
        cin>>ff[i].s;
    for (int i=1; i<=n; i++)
        cin>>ff[i].f;
    sort(ff+1,ff+n+1);
    for (int i=1; i<=n; i++)
    {
        b[i]=ff[i].f;
        a[i]=ff[i].s;
    }
    for (int i=1; i<=m; i++)
        cin>>c[i];
    for (int i=1; i<=m; i++)
        cin>>d[i];
    ll r=m,ans=4*(ll)1e18+20;
    while (r>0)
    {
        if (s-d[r]>=0) break;
        r--;
    }
    ans=min(ans,max((ll)0,k-c[r])*x);
    for (int i=1; i<=n; i++)
    if (b[i]<=s)
    {
        while (r>0)
        {
            if (s-b[i]-d[r]>=0) break;
            r--;
        }
        ll res=max((ll)0,k-c[r])*a[i];
        if (res<ans) ans=res;
    }
    cout<<ans<<endl;
}