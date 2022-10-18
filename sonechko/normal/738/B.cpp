#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000000000000;
const int N = 200000+10;
const int M = 100;
const int N2 = 100+5;
const int N3 = 1000+5;
const int N4 = 10000+5;
const int N5 = 100000+5;
const int N6 = 1000000+5;
const int N7 = 10000000+5;
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
#define y1 dbfuebfwkmjjzdbhqfja
#define time zdfheajbrkjasghduw
#define ull unsigned long long
#define randomize srand(time(NULL))
#define next ifhiuebf
#define last dkbffjrb
#define pb push_back
#define left second
#define pii pair<ll,ll>
int a[N3][N3],f[N3][N3],b[N3][N3],l[N3][N3];
int r[N3][N3];
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    sync;
    #endif // LOCAL
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
    {
        cin>>a[i][j];
        f[i][j]=f[i-1][j]+a[i][j];
        l[i][j]=l[i][j-1]+a[i][j];
    }
    for (int i=n; i>=1; i--)
        for (int j=m; j>=1; j--)
    {
        b[i][j]=b[i+1][j]+a[i][j];
        r[i][j]=r[i][j+1]+a[i][j];
    }
    int ans=0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (a[i][j]==0)
    {
        ans+=(b[i][j]>0)+(f[i][j]>0)+(l[i][j]>0)
        +(r[i][j]>0);
    }
    cout<<ans<<endl;
}