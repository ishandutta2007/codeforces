#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000000000000;
const int N = 100+10;
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
ll dp[N][N][N], a[N][N], ft1[N][N][N], ft2[N][N][N];
int c[N];
ll mini(int i, int p, int j)
{
    return min(ft1[i][p][j-1],ft2[i][p][j+1]);
}
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    sync;
    #endif // LOCAL
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1; i<=n; i++)
        cin>>c[i];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            cin>>a[i][j];
            if (c[i]!=0)
                a[i][j]=0;
        }
    for (int i=1; i<=n; i++)
    for (int j=0; j<=m; j++)
    for (int p=0; p<=k; p++)
    dp[i][j][p]=MOD;
    for (int i=1; i<=n; i++)
    {
        int l1=1;
        int r1=m;
        if (c[i]!=0) {l1=c[i];
        r1=c[i];}
        for (int j=l1; j<=r1; j++)
        for (int p=1; p<=min(k,i); p++)
        {
            dp[i][j][p]=dp[i-1][j][p]+a[i][j];
            if (i!=1&&p!=1)
            {
                //cout<<i<<" "<<j<<" "<<p<<" "<<mini(i-1,p-1,j)<<endl;
            dp[i][j][p]=min(dp[i][j][p],mini(i-1,p-1,j)+a[i][j]);
            }
        }
        for (int p=1; p<=k; p++)
        {
            ft1[i][p][0]=MOD;
            for (int j=1; j<=m; j++)
                ft1[i][p][j]=min(ft1[i][p][j-1],dp[i][j][p]);
            ft2[i][p][m+1]=MOD;
            for (int j=m; j>=1; j--)
                ft2[i][p][j]=min(ft2[i][p][j+1],dp[i][j][p]);
        }
    }
    if (ft1[n][k][m]==MOD)
        cout<<-1<<endl;
    else cout<<ft1[n][k][m]<<endl;
}