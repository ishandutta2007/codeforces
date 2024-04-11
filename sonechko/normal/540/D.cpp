#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000000000000;
const int N = 100+10;
const int M = 100;
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
ld dp[N][N][N],ans1,ans2,ans3;
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    sync;
    #endif // LOCAL
    int n,m,r;
    cin>>n>>m>>r;
    dp[n][m][r]=1;
    for (int i=n; i>=0; i--)
        for (int j=m; j>=0; j--)
        for (int k=r; k>=0; k--)
    {
        if (i==0)
        {
            ans2+=dp[i][j][k];
        } else
        if (j==0)
        {
            ans3+=dp[i][j][k];
        } else
        if (k==0)
        {
            ans1+=dp[i][j][k];
        } else
        {
            ld f=i*j+j*k+i*k;
            dp[i-1][j][k]+=(ld)k*(ld)i/f*dp[i][j][k];
            dp[i][j-1][k]+=(ld)i*(ld)j/f*dp[i][j][k];
            dp[i][j][k-1]+=(ld)j*(ld)k/f*dp[i][j][k];
        }
    }
    outld(10);
    cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
}