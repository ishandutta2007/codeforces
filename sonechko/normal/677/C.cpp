#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 100002;
const int M = 10;
const string s2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string s1 = "abcdefghijklmnopqrstuvwxyz";
const string s3 = "0123456789";
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
ll ans[N];
int main()
{
    int a[N];
    string s;
    cin>>s;
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]>='0'&&s[i]<='9') a[i]=s[i]-'0';
        if (s[i]>='A'&&s[i]<='Z') a[i]=s[i]-'A'+10;
        if (s[i]>='a'&&s[i]<='z') a[i]=s[i]-'a'+36;
        if (s[i]=='-') a[i]=62;
        if (s[i]=='_') a[i]=63;
    }
    for (int i=0; i<=63; i++)
        for (int j=0; j<=63; j++)
            ans[(i&j)]++;
    ll res=1;
    for (int i=0; i<s.size(); i++)
        res=(res*ans[a[i]])mod;
    cout<<res<<endl;
}