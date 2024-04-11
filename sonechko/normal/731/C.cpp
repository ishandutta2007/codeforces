#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000000000000;
const int N = 200000+10;
const int M = 1000;
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
int p[N],t,b[N],use[N];
vector<int> v[N];
void update(int l, int r)
{
    v[l].push_back(r);
}
void dfs(int l)
{
    use[l]=1;
    t++;
    b[t]=p[l];
    for (int i=0; i<v[l].size(); i++)
        if (use[v[l][i]]==0)
        dfs(v[l][i]);
}
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    #endif // LOCAL
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1; i<=n; i++)
        cin>>p[i];
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        update(l,r);
        update(r,l);
    }
    int ans=0;
    for (int i=1; i<=n; i++)
    if (use[i]==0)
    {
        t=0;
        dfs(i);
        sort(b+1,b+t+1);
        int res=1;
        int f=1;
        for (int j=2; j<=t; j++)
            if (b[j]==b[j-1])
            {
                res=max(res,j-f+1);
            } else
            {
                f=j;
            }
        ans+=t-res;
    }
    cout<<ans<<endl;
}