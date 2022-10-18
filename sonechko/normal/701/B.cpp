#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 3000000+5;
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
ll use1[N],use2[N],l1,r1;
int main()
{
#ifndef ONLINE_JUDGE
    filestxt;
#endif
sync;
ll n,m;
cin>>n>>m;
ll ans=n*n;
for (ll i=1; i<=m; i++)
{
    int l,r;
    cin>>l>>r;
    if (use1[l]==1&&use2[r]==1) cout<<ans<<" "; else
    if (use1[l]==0&&use2[r]==0) {ans-=n-l1+n-r1-1; use1[l]=1; use2[r]=1; l1++; r1++; cout<<ans<<" ";} else
    {
    if (use2[r]==1) {ans-=n-r1; l1++;} else {ans-=n-l1; r1++;}
    cout<<ans<<" ";
    use1[l]=1;
    use2[r]=1;
    }
}
}