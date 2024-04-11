#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 100000+5;
const int M = 10;
const string st2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string s1 = "abcdefghijklmnopqrstuvwxyz";
const string d = ".BRG";
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
//#define s second
#define ll long long
#define f first
#define mp make_pair
#define y1 dbfuebfwkjNBSciwbe
#define time zdfheajbrkjasghduw
#define ull unsigned long long
int a[N],b[N];
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
        cin>>a[i];
    for (int i=1; i<=m; i++)
        cin>>b[i];
    int k=1;
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        while (k<=m)
            if (b[k+1]>a[i]) break; else k++;
        if (k==m+1) k--;
        if (k==m) k--;
        ans=max(ans,min(max(a[i],b[max(1,k)])-min(a[i],b[max(1,k)]),max(a[i],b[k+1])-min(a[i],b[k+1])));
    }
    cout<<ans<<endl;
}