#include<bits/stdc++.h>

const long long MOD = 10e9 + 7;
#define mod % MOD
#define filesio(x) freopen(x + ".in", "r", stdin); freopen(x + ".out", "w", stdout);
#define filesds(x) freopen(x + ".dat", "r", stdin); freopen(x + ".sol", "w', stdout);
#define filestt(x) freopen(x + ".txt", "r", stdin); freopen(x + ".txt", "w", stdout);
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
#define ll long long
#define endl "\n"

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    for (int i=0; i<n; i++)
        cin>>a[i];
    sort(a,a+n);
    reverse(a,a+n);
    int k=0;
    for (int i=0; i<n; i++)
    {
        k+=a[i];
        if (k>=m) {cout<<i+1; return 0;}
    }

}