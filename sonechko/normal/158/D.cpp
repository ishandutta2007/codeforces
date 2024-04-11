#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 300005;
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
int a[N],b[N],ans;
int main()
{
    sync;
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    ans=INT_MIN;
    for (int i=1; i<=n; i++)
        if (n%i==0&&n/i>2)
    {
        for (int j=0; j<=i; j++)
            b[j]=0;
        for (int j=1; j<=n; j++)
            b[j%i]+=a[j];
        for (int j=0; j<i; j++)
        ans=max(ans,b[j]);
    }
    cout<<ans<<endl;
}