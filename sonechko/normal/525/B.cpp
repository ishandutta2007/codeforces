#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 200005;
const int M = 10;
const string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
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
char a[N];
int b[N];
int main()
{
    string s;
    cin>>s;
    for (int i=0; i<s.size(); i++)
        a[i+1]=s[i];
    int n=s.size(),m;
    cin>>m;
    for (int i=1; i<=m; i++)
    {
        int l;
        cin>>l;
        b[l]=1-b[l];
    }
    int l=0;
    for (int i=1; i<=n/2; i++)
    {
        l+=b[i];
        if (l%2==1) {char ch=a[i]; a[i]=a[n-i+1]; a[n-i+1]=ch;}
    }
    for (int i=1; i<=n; i++)
        cout<<a[i];
    cout<<endl;
}