#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const long long L = 1000000;
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define files freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, sizeof(x), y)
#define sqr(a) ((a) * (a))
#define ll long long
#define endl "\n"
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define f first
#define mp make_pair
map<string,int> mt,m1;
int n,m,ans;
string a[40],b[40];
void rec(char ch, string s)
{
    if (s.size()+1==n) {if (mt[ch+s]==0) ans++; mt[ch+s]=1; return;}
    if (m1[ch+s]==1) return;
    m1[ch+s]=1;
    for (int i=1; i<=m; i++)
    {
        string t=b[i],d=a[i];
        if (ch==t[0]) {rec(d[0],d[1]+s);}
    }
}
int main()
{
    cin>>n>>m;
    for (int i=1; i<=m; i++)
        cin>>a[i]>>b[i];
    rec('a',"");
    cout<<ans<<endl;
}