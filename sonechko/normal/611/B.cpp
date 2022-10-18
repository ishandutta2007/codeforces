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
ll ans,n,m;
int main()
{
    sync;
    cin>>n>>m;
    string s(63, '1');
    for (int r=s.size()-2; r>=1; r--)
    {
        for (int j=1; j<r; j++)
    {
        s[j]='0';
        ll t=1,k=0;
        for (int i=1; i<=r; i++)
        {
            if (i!=j) k+=t;
            t*=2;
        }
        if (k>=n&&k<=m) ans++;
        s[j]='1';
    }
    s[r]='0';
    }
    cout<<ans<<endl;
}