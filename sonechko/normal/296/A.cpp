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
#define ll unsigned long long
#define endl "\n"

int main()
{
    int n;
    cin>>n;
    int b[1001];
    ms(b,0);
    for (int i=0; i<n; i++)
    {
        int l;
        cin>>l;
        b[l]++;
    }
    for (int i=0; i<1001; i++)
    if (b[i]>(n+1)/2) {cout<<"NO"; return 0;}
    cout<<"YES";
}