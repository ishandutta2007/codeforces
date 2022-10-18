#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000000000000;
const int N = 5000+10;
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
int a[N][N];
short b[N],pref[N][N];
bool use[N];
int dp[N][N];
vector<int> c[N];
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    sync;
    #endif // LOCAL
    int n,m,t;
    cin>>n>>m>>t;
    for (int i=1; i<=m; i++)
    {
        int l,r,k;
        cin>>l>>r>>k;
        if (a[l][r]==0||a[l][r]>k) a[l][r]=k;
        b[r]++;
        c[r].push_back(l);
    }
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    dp[i][j]=INT_MAX;
    use[1]=1;
    for (int j=1; j<=n; j++)
        if (a[1][j]>0) b[j]--;
    dp[1][1]=0;
    for (int k=2; k<=n; k++)
    {
        int x=0;
        for (int i=1; i<=n; i++)
            if (use[i]==0&&b[i]==0) {x=i; break;}
        use[x]=1;
        for (int j=1; j<=n; j++)
        if (a[x][j]>0) b[j]--;
        for (int i=2; i<=n; i++)
            for (int j=0; j<c[x].size(); j++)
        {
            int to=c[x][j];
            if (dp[to][i-1]!=INT_MAX&&(ll)dp[to][i-1]+(ll)a[to][x]<(ll)dp[x][i]) {dp[x][i]=dp[to][i-1]+a[to][x];
            pref[x][i]=to;}
    }
    }
    for (int i=n; i>=1; i--)
    if (dp[n][i]<=t)
    {
        cout<<i<<endl;
        int l=n;
        int r=i;
        for (int j=i; j>=1; j--)
        {
            b[j]=l;
            l=pref[l][r];
            r--;
        }
        for (int j=1; j<=i; j++)
        cout<<b[j]<<" ";
        cout<<endl;
        return 0;
    }
}