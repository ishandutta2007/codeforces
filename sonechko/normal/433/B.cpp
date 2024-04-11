#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;
const int N = 1000000+10;
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
ll a[N],sum1[N],sum2[N];
int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        sum1[i]=sum1[i-1]+a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1; i<=n; i++)
    {
        sum2[i]=sum2[i-1]+a[i];
    }
    int m;
    cin>>m;
    for (int i=1; i<=m; i++)
    {
        int k,l,r;
        cin>>k>>l>>r;
        if (k==1) cout<<sum1[r]-sum1[l-1]<<endl; else
            cout<<sum2[r]-sum2[l-1]<<endl;
    }
}