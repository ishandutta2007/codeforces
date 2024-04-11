#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int M = 500001;
const int N = 100006;
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
#define next isehfejrbw

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    int b[n+1];
    for (int i=1; i<=n; i++)
        {
            int l;
            cin>>l;
            b[l]=i;
        }
    vector<int> v[n+1];
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        l=b[l];
        r=b[r];
        v[l].push_back(r);
        v[r].push_back(l);
    }
    int l=1;
    int r=0;
    ll ans=0;
    while (r<n)
    {
        //cout<<l<<" "<<r<<endl;
        r++;
        int p=l;
        for (int i=0; i<v[r].size(); i++)
        if (v[r][i]>=p&&v[r][i]<=r) l=max(l,v[r][i]+1);
        ans+=((long long)r-(long long)l+1);

    }
    cout<<ans<<endl;
}