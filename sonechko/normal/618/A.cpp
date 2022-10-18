#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
#define ll long long
#define endl "\n"
#define ld long double
#define outld(l) cout.precision(l);cout << fixed

int main()
{
    int n;
    cin>>n;
    int a[200000];
    int l=0;
    for (int i=1; i<=n; i++)
    {
        l++;
        a[l]=1;
        while (l>1&&a[l]==a[l-1])
        {
            l--;
            a[l]=a[l]+1;
        }
    }
    for (int i=1; i<=l; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}