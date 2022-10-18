#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 201;
const int M = 10;
const string st2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string s1 = "abcdefghijklmnopqrstuvwxyz";
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
int main()
{
    int n,m;
    cin>>n>>m;
    if (n>=0&&m>=0) cout<<"0 "<<n+m<<" "<<n+m<<" 0"<<endl; else
    if (m>=0) cout<<n-m<<" 0 0 "<<m-n<<endl; else
    if (n>=0) cout<<"0 "<<m-n<<" "<<n-m<<" 0"<<endl; else
    cout<<n+m<<" 0 0 "<<n+m<<endl;
}