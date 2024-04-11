#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 100002;
const int M = 10;
const string st2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string s1 = "abcdefghijklmnopqrstuvwxyz";
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
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
#define next ljjdfienf
int a[1001][1001],t[10001],x[10001],y[10001],z[10001],b[10001],c[10001];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1; i<=k; i++)
    {
        int k;
        cin>>k;
        if (k==1) cin>>b[i]; else
        if (k==2) cin>>c[i]; else cin>>x[i]>>y[i]>>z[i];
        t[i]=k;
    }
    for (int i=k; i>=1; i--)
    {
        if (t[i]==3) a[x[i]][y[i]]=z[i]; else
        if (t[i]==1)
        {
            int p=a[b[i]][m];
            for (int j=m; j>=2; j--)
                a[b[i]][j]=a[b[i]][j-1];
            a[b[i]][1]=p;
        } else
        if (t[i]==2)
        {
            int p=a[n][c[i]];
            for (int j=n; j>=2; j--)
                a[j][c[i]]=a[j-1][c[i]];
            a[1][c[i]]=p;
        }
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}