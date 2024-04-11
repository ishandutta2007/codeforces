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
string a[N];
bool good(string s, char l, char r)
{
    for (int i=0; i<s.size(); i++)
        if (s[i]!=l&&s[i]!=r) return false;
    return true;
}
int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    cin>>a[i];
    int ans=0;
    for (int i=1; i<chara.size(); i++)
    for (int j=1; j<chara.size(); j++)
    {
        int res=0;
        for (int k=1; k<=n; k++)
        if (good(a[k],chara[i],chara[j])) res+=a[k].size();
        ans=max(ans,res);
    }
    cout<<ans<<endl;
}