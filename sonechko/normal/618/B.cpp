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
    int a[n+1][n+1];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
        {
            cin>>a[i][j];
            if (a[i][j]==0) a[i][j]=0;
        }
    int ans[n+1];
    for (int i=1; i<=n; i++)
        ans[i]=100;
    for (int k=1; k<n; k++)
    {
        int l=100, r=100;
        for (int i=1; i<=n; i++)
         {
             int kk=0;
             for (int j=1; j<=n; j++)
                if (a[i][j]>kk) kk=a[i][j];
             if (kk==k) {l=i; break;}
         }
        ans[l]=k;
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
        if (a[i][j]<=k) a[i][j]=0;
    }
    for (int i=1; i<=n; i++)
        if (ans[i]==100) cout<<n<<" "; else cout<<ans[i]<<" ";
    cout<<endl;
}