#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const long long L = 1000000;
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define files freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
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

int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
        for (int k=1; k<=n; k++)
    if (a[i]!=a[j]&&a[i]!=a[k]&&a[j]!=a[k]&&abs(a[i]-a[j])<=2&&abs(a[i]-a[k])<=2&&abs(a[j]-a[k])<=2) {cout<<"YES"<<endl; return 0;}
    cout<<"NO"<<endl;
}