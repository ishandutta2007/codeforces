#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 500004;
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
ll n,b[N],a[N],k,t,p,ans;
int main()
{
    sync;
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        {
            cin>>a[i];
            k+=a[i];
        }
    if (abs(k)%3!=0) {cout<<0<<endl; return 0;} else
    if (k<0) {t=-(abs(k)/3);} else t=k/3;
    for (int i=1; i<=n; i++)
    {
        p+=a[i];
        if (p==t) b[i]=b[i-1]+1; else b[i]=b[i-1];
    }
    p=0;
    for (int i=n; i>=3; i--)
    {
        p+=a[i];
        if (p==t) ans+=b[i-2];
    }
    cout<<ans<<endl;
}