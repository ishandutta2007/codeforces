#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 1000+10;
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
ll a[N],b[N],l,r,c[N][N];
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    sync;
    #endif // LOCAL
    int n;
    cin>>n;
    ll l1=0,r1=0;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    {
        cin>>c[i][j];
        if (c[i][j]==0)
        {
            l1=i;
            r1=j;
        }
        a[i]+=c[i][j];
        b[j]+=c[i][j];
        if (i==j) l+=c[i][j];
        if (i+j==n+1) r+=c[i][j];
    }
    ll k=1;
    if (l1==1) k=2;
    c[l1][r1]=max((long long)1,abs(a[k]-a[l1]));
    if (l1==r1) l+=c[l1][r1];
    if (l1+r1==n+1) r+=c[l1][r1];
    a[l1]+=c[l1][r1];
    b[r1]+=c[l1][r1];
    if (l!=r)
    {
        cout<<-1<<endl;
        return 0;
    }
    for (int i=1; i<=n; i++)
    if (a[i]!=l||b[i]!=l)
    {
        cout<<-1<<endl;
        return 0;
    }
    cout<<c[l1][r1]<<endl;
}