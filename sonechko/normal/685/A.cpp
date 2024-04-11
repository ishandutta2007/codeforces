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
int use[20],use1[20];
int rec(int n, int m, int l, int r)
{
    int ans=0;
    for (int i=0; i<=n; i++)
        for (int j=0; j<=m; j++)
    {
        int u[10];
        for (int ij=0; ij<10; ij++)
            use[ij]=0;
        int t=i, ph=0;
        if (t==0) use[0]++;
        if (t==0) ph++;
        while (t>0)
        {
            use[t%7]++;
            ph++;
            t/=7;
        }
        use[0]+=l-ph;
        t=j;
        ph=0;
        if (t==0) use[0]++;
        if (t==0) ph++;
        while (t>0)
        {
            use[t%7]++;
            ph++;
            t/=7;
        }
        use[0]+=r-ph;
        for (int ij=0; ij<=7; ij++)
        if (use[ij]>1) {ans--; break;}
        ans++;
    }
    return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    n--;
    m--;
    int k1=0,k2=0,p=n;
    if (n==0) k1++;
    while (n>0)
    {
        n/=7;
        k1++;
    }
    n=p;
    p=m;
    if (m==0) k2++;
    while (m>0)
    {
        m/=7;
        k2++;
    }
    m=p;
    if (k1+k2>7) {cout<<0<<endl; return 0;}
    cout<<rec(n,m,k1,k2)<<endl;
}