#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const long long L = 300000;
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
string s;
int n,m,b[L];
bool good(int l)
{
    for (int i=1; i<=n; i++)
    if (s[i]=='0')
    {
        int k=b[min(n,i+l)]-b[max(0,i-l-1)];
        //cout<<l<<" "<<i<<" "<<": "<<k<<endl;
        if (k>=m+1) return true;
    }
    return false;
}
int main()
{
    cin>>n>>m;
    cin>>s;
    s='.'+s;
    b[0]=0;
    for (int i=1; i<=n; i++)
        if (s[i]=='0') b[i]=b[i-1]+1; else b[i]=b[i-1];
    int l=1,r=n;
    while (r-l>1)
    {
        int p=(l+r)/2;
        if (good(p)) r=p; else l=p;
    }
    if (good(l)) cout<<l<<endl; else cout<<r<<endl;
}