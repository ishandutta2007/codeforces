#include<bits/stdc++.h>

const long long MOD = 1e9 + 7;
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
#define ll unsigned long long
#define endl "\n"

using namespace std;

int main()
{
    int n,l=0, r=0;
    cin>>n;
    for (int i=0; i<n; i++)
    {
        int k,p;
        cin>>k>>p;
        l+=k;
        r+=p;
    }
    int ans;
    if (l>n-l) ans = n-l; else ans = l;
    if (r>n-r) ans+= n-r; else ans+= r;
    cout<<ans<<endl;
}