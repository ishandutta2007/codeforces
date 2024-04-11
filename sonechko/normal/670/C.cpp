#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 100002;
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
int a[1000001],c[1000001],d[1000001];
map<int,int> b;
int main()
{
    int n;
    cin>>n;
    int p=0;
    for (int i=1; i<=n; i++)
        {
            cin>>a[i];
            b[a[i]]++;
        }
    int m;
    cin>>m;
    for (int i=1; i<=m; i++)
    {
        int l;
        cin>>l;
        c[i]=b[l];
    }
    for (int i=1; i<=m; i++)
    {
        int l;
        cin>>l;
        d[i]=b[l];
    }
    int t=1;
    for (int i=1; i<=m; i++)
        if (c[i]>c[t]||(c[i]==c[t]&&d[i]>d[t])) t=i;
    cout<<t<<endl;
}