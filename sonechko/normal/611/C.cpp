#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;
const int N = 500+10;
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
char a[N][N];
int l[N][N],r[N][N],sum[N][N],b[N][N];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        cin>>a[i][j];
    for (int i=1; i<=n; i++)
    {
        for (int j=2; j<=m; j++)
        {
            l[i][j]=l[i][j-1];
            if (a[i][j]=='.'&&a[i][j-1]=='.') {l[i][j]++; b[i][j]++;}
        }
    }
    for (int j=1; j<=m; j++)
    {
        for (int i=2; i<=n; i++)
        {
            r[i][j]=r[i-1][j];
            if (a[i][j]=='.'&&a[i-1][j]=='.')
                {r[i][j]++; b[i][j]++;}
        }
    }
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
    {
        sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+b[i][j];
    }
    int k;
    cin>>k;
    for (int i=1; i<=k; i++)
    {
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        cout<<(l[l1][r2]-l[l1][r1])+(r[l2][r1]-r[l1][r1])+(sum[l2][r2]-sum[l2][r1]-sum[l1][r2]+sum[l1][r1])<<endl;
    }
}