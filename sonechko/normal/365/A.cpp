#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 105;
const int M = 10;
const string charA = ".ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string chara = ".abcdefghijklmnopqrstuvwxyz";
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, sizeof(x), y)
#define sqr(a) ((a) * (a))
#define endl "\n"
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define ll long long
#define f first
#define mp make_pair
#define next ljjdfienf
int a[M];
int main()
{
    int n,k,ans=0;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        for (int j=0; j<s.size(); j++)
        {
            int k=s[j]-'0';
            a[k]=1;
        }
        int l=0;
        for (int j=0; j<=k; j++)
        {
            if (a[j]==0) l=1;
            a[j]=0;
        }
        if (l==0) ans++;
    }
    cout<<ans<<endl;
}