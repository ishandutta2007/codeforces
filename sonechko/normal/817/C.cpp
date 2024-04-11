#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ld long double

const int N = 1e5 + 11;
const ll MOD = 1e18;
#define mod %MOD
ll dp[20][200];
ll res(ll n, ll sum)
{
    string s="";
    ll ans=0;
    if (n==MOD) {n--; if (sum==1) ans++;}
    while (n>0)
    {
        int k=n%10;
        char ch=k+'0';
        string p="";
        p+=ch;
        s=p+s;
        n/=10;
    }
    while (s.size()<18)
        s="0"+s;
    int sums=0;
    for (int i=0; i<s.size(); i++)
    {
        int d=s[i]-'0';
        for (int j=0; j<d; j++)
        if (sums+j<=sum) ans+=dp[i+2][sum-sums-j];
        sums+=d;
    }
    if (sums==sum) ans++;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,s;
    cin>>n>>s;
    ll ans=0;
    dp[19][0]=1;
    for (int i=18; i>=0; i--)
    for (int j=0; j<=162; j++)
    for (int k=0; k<=9; k++)
    {
        dp[i][j+k]+=dp[i+1][j];
    }
    for (ll i=1; i<=162; i++)
    {
        if (i+s<=n) ans+=res(n,i)-res(i+s-1,i);
    }
    cout<<ans<<endl;
}