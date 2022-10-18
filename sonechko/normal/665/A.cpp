#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 1000000;
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
#define next ljjdfienf
int main()
{

    //!!A!!
    int n,m,l,r;
    cin>>n>>m>>l>>r;
    string s;
    cin>>s;
    int l1=(s[0]-'0')*10+(s[1]-'0');
    int r1=(s[3]-'0')*10+(s[4]-'0');
    int start = l1*60+r1;
    int finish = l1*60+r1+m,ans=0;
    for (int i=5*60; i<=24*60-1; i++)
        if ((i-5*60)%l==0&&i+r>start&&i<finish) ans++;
    cout<<ans<<endl;
}