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
    int n, x, y, k=0;
    cin>>n;
    int a[n];
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
        k+=a[i];
    }
    cin>>x>>y;
    int l=0;
    for (int i=0; i<n; i++)
    {
        l+=a[i];
        int r = k-l;
        if ((l>=x)&&(l<=y)&&(r>=x)&&(r<=y)) {cout<<i+2; return 0;}
    }
    cout<<0;
}