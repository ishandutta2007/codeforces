#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 500+5;
const int M = 10;
const string st2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string s1 = "abcdefghijklmnopqrstuvwxyz";
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define filestxt freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, sizeof(x), y)
#define sqr(a) ((a) * (a))
//#define endl "\n"
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define ll long long
#define f first
#define mp make_pair
#define y1 dbfuebfwkjNBSciwbe
#define time zdfheajbrkjasghduw
int use[N],a[N],use1[N],res[N],mm;
int us[N][N];
vector<int> vv[N];
void rec(int m, int pred)
{
    use1[m]=1;
    res[m]=1;
    for (int i=0; i<vv[m].size(); i++)
    if (use1[vv[m][i]]==0)
    {
        rec(vv[m][i],m);
    }
}
int main()
{
    #ifdef LOCAL
    filestxt;
    #else

    #endif // LOCAL
    int n,m;
    cin>>n>>m;
    mm=m;
    int t=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        t+=a[i];
    }
    sort(a+1,a+n+1);
    use[0]=1;
for (int i=0; i<=m; i++)
    us[i][0]=1;
    for (int i=1; i<=n; i++)
        for (int j=m-a[i]; j>=0; j--)
        if (use[j]>0)
        {
            use[j+a[i]]=1;
            //cout<<j<<" "<<a[i]<<endl;

            for (int k=m-a[i]; k>=0; k--)
                if (us[j][k]==1)
                {us[j+a[i]][k+a[i]]=1;
                us[j+a[i]][k]=1;}
        }
    int ans=0;
    for (int i=0; i<=m; i++) if (us[m][i]==1) ans++;
    cout<<ans<<endl;
    for (int i=0; i<=m; i++)
        if (us[m][i]==1) cout<<i<<" ";
    cout<<endl;
}

/// wGFT4KZJ