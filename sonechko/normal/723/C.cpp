#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000000000000;
const int N = 10000+10;
const int M = 100;
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
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define ll long long
#define f first
#define mp make_pair
#define y1 dbfuebfwkjNBSciwbe
#define time zdfheajbrkjasghduw
#define ull unsigned long long
#define randomize srand(time(NULL))
#define next ifhiuebf
#define last dkbffjrb
int use[N],a[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        if (a[i]<=m) use[a[i]]++;
    }
    int maxi=n/m,ans=0;
    cout<<maxi<<" ";
    for (int i=1; i<=m; i++)
    {
        if (use[i]<maxi)
        {
            for (int j=1; j<=n; j++)
                {
                    if (use[i]>=maxi) break;
                    if (a[j]>m||use[a[j]]>maxi)
            {
                //cout<<j<<" "<<i<<" "<<use[i]<<endl;
                ans++;
                use[i]++;
                if (a[j]<=m) use[a[j]]--;
                a[j]=i;
            }
                }
        }
    }
    cout<<ans<<endl;
    for (int i=1; i<=n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}