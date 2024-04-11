#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const long long L = 200005;
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, sizeof(x), y)
#define sqr(a) ((a) * (a))
#define ll long long
#define endl "\n"
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define f first
#define mp make_pair
ll a[L], ans[L];
int main()
{
    ll n,m;
    cin>>n>>m;
    ll l=0,r=0;
    ll t1,t2;
    cin>>t1>>t2;
    l=1;
    r=1;
    a[l]=t1+t2;
    ans[1]=a[l];
    for (int i=2; i<=n; i++)
    {
        cin>>t1>>t2;
        while (l<=r&&a[l]<=t1)
        {
            l++;
        }
        if (r-l+1<=m)
        {
            r++;
            if (l==r) a[r]=t1+t2; else a[r]=a[r-1]+t2;
            ans[i]=a[r];
        } else ans[i]=-1;
    }
    for (int i=1; i<=n; i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}