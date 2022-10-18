#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const long long L = 105;
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
int a[L][L],n,m,k;
int main()
{
    cin>>k>>n>>m;
    int l=0;
    int r=-1;
    int p=k/2;
    int g=(k+1)/2;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
    {
        int k1=0;
        int k2=0;
        if (p==0&&g==0) break;
        if (a[i-1][j]!=0)
        {
            if (a[i-1][j]%2==0) k1++; else k2++;
        }
        if (a[i][j-1]!=0)
        {
            if (a[i][j-1]%2==0) k1++; else k2++;
        }
        if (k1==0&&k2==0)
            {
                if (p>=g) {p--; l+=2; a[i][j]=l;} else
                {
                    g--;
                    r+=2;
                    a[i][j]=r;
                }
            } else
        if (k1==0&&p>0)
        {
            p--;
            l+=2;
            a[i][j]=l;
        } else
        if (k2==0&&g>0)
        {
            g--;
            r+=2;
            a[i][j]=r;
        }
        //cout<<i<<" "<<j<<" : "<<k1<<" "<<k2<<" : "<<a[i][j]<<" "<<p<<" "<<g<<endl;
    }
    if (p==0&&g==0)

        {
            for (int i=1; i<=n; i++)
            {
                for (int j=1; j<=m; j++)
                    cout<<a[i][j]<<" ";
            cout<<endl;
            }

        } else cout<<-1<<endl;
}