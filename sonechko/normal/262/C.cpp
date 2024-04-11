#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 1000000;
const int M = 10;
const string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
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

int main()
{
    int m,k=INT_MAX;
    cin>>m;
    int b[m+1];
    for (int i=1; i<=m; i++)
    {
        int l;
        cin>>l;
        k=min(k,l);
    }
    int n;
    cin>>n;
    int a[n+1];
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int ans=0;
    int p=0,t=0;
    for (int i=n; i>=1; i--)
    {
        if (p==k&&t==0) t=1; else
        if (p==k&&t==1) {p=0; t=0;} else {p++; ans+=a[i];}
    }
    cout<<ans<<endl;
}