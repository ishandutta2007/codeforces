#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 100000+5;
const int M = 10;
const string st2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string s1 = "abcdefghijklmnopqrstuvwxyz";
const string d = ".BRG";
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define filestxt freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, sizeof(x), y)
#define sqr(a) ((a) * (a))
#define endl "\n"
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
//#define s second
#define ll long long
#define f first
#define mp make_pair
#define y1 dbfuebfwkjNBSciwbe
#define time zdfheajbrkjasghduw
#define ull unsigned long long

int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    sync;
    #endif // LOCAL
    ll d,k,a,b,t,ans=0,res=0;
    cin>>d>>k>>a>>b>>t;
    if (k>=d) {cout<<a*d<<endl; return 0;}
    ans=a*k;
    d-=k;
    ll c=(d/k)*t +(d/k)*k*a +(d%k) *a;
    if (d%k!=0) c+=t;
    res=(d/k)*t +(d/k)*k*a  + (d%k) *b;
    if (d*b<res) res=d*b;
    if (c<res) res=c;
    cout<<res+ans<<endl;
}