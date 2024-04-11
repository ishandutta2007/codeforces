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
ll a[N];
int main()
{
    int n,m,k;
    cin>>n>>k>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    ll ans=0,l=0;
    for (int i=1; i<=n; i++)
    if (l+a[i]<=k) l+=a[i]; else
    {
        int t=k-a[i];
        int p=l-t;
        //cout<<i<<" "<<t<<" "<<p<<endl;
        ans+=p/m;
        l-=p/m*m;
        if (p%m!=0) {ans++; l-=m;}
        if (l<0) l=0;
        //cout<<l<<endl;
        l+=a[i];
    }
    ans+=l/m;
    if (l%m!=0) ans++;
    cout<<ans<<endl;
}