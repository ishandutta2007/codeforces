#include<bits/stdc++.h>

using namespace std;

const long long MOD = INT_MAX;
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
int b[5001], c[5001], d[5001], e[5001];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1; i<=k; i++)
    {
        int l,r,p;
        cin>>p>>l>>r;
        if (p==1) {b[l]=r;d[l]=i;} else {c[l]=r;e[l]=i;}
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
            if (d[i]>e[j]) cout<<b[i]<<" "; else cout<<c[j]<<" ";
        cout<<endl;
    }

}