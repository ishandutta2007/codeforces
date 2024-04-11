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
    int n,k;
    cin>>n>>k;
    int b[n];
    for (int i=0; i<n; i++)
    {
        int l;
        cin>>l;
        b[i] = (i==0 ? l : b[i-1]+l);
    }
    int ans=MOD;
    int res;
    for (int i=0; i<n-k+1; i++)
    {
        int l = (i==0 ? b[i+k-1] : b[i+k-1]-b[i-1]);
        if (l<ans)
        {
            ans = l;
            res = i+1;
        }
    }
    cout<<res<<endl;
}