#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 100005;
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
int n,l,r,x,a[N],b[N],ans,k;
void rec(int t)
{
    if (t==n+1)
    {
        int tl=INT_MAX,tr=INT_MIN,tx=0;
        for (int i=1; i<=k; i++)
        {
            tl=min(tl,b[i]);
            tr=max(tr,b[i]);
            tx+=b[i];
        }
        if (tx>=l&&tx<=r&&tr-tl>=x) ans++;
        return;
    }
    rec(t+1);
    k++;
    b[k]=a[t];
    rec(t+1);
    k--;
}
int main()
{
    sync;
    cin>>n>>l>>r>>x;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    rec(1);
    cout<<ans<<endl;
}