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
    int n;
    cin>>n;
    int a[n];
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int m;
    cin>>m;
    int ans=0, k=0;
    for (int i=0; i<m; i++)
    {
        int l;
        cin>>l;
        for (int j=0; j<n; j++)
        {
            if (l%a[j]==0)
            {
                if (l/a[j]>ans) {ans=l/a[j]; k=1;} else
                    if (l/a[j]==ans) k++;
            }
        }
    }
    cout<<k<<endl;
}