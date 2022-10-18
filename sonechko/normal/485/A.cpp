#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 1000005;
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
int a[N];
int main()
{
    /**string s1,s2;
    cin>>s1;
    string s=s1;
    for (int i=1; i<s.size(); i++)
    {
        int l=a[i-1];
        while (l>0&&s[i]!=s[l])
        l=a[l-1];
        if (s[i]==s[l]) l++;
        a[i]=l;
    }
    cout<<s.size()-a[s.size()-1]<<endl;
    **/
    ll n,m;
    cin>>n>>m;
    for (int i=1; i<=10000000; i++)
    {
        if (n%m==0) {cout<<"Yes"<<endl; return 0;}
        n=n+(n%m);
    }
    cout<<"No"<<endl;
}