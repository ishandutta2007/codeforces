#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const long long L = 300000;
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
int b[1000001];
int main()
{
    int n;
    cin>>n;
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        b[l]++;
        if (b[l]>b[ans]) ans=l;
    }
    cout<<ans<<endl;
}