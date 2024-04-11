#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000000000000;
const int N = 100000+10;
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
int a[N],b[N],dp[N][3];
int main()
{

    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
       {
           int k;
           cin>>k;
           if (k==1||k==3) a[i]=1;
           if (k==2||k==3) b[i]=1;
       }
    for (int i=1; i<=n; i++)
    {
        dp[i][0]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
        if (a[i]==1) dp[i][1]=max(dp[i-1][0],dp[i-1][2])+1;
        if (b[i]==1) dp[i][2]=max(dp[i-1][0],dp[i-1][1])+1;
        //cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
    }
    cout<<n-max(dp[n][0],max(dp[n][1],dp[n][2]))<<endl;
}