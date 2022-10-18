#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 100005;
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
int nsd(int l, int r)
{
    while (l>0&&r>0)
        if (l>r) l%=r; else
        r%=l;
    return (l+r);
}
int b[N],a[N],m;
int main()
{
    sync;
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<n; i++)
        if (nsd(a[i],a[i+1])!=1)
    {
        m++;
        b[m]=1;
        m++;
        b[m]=a[i+1];
    } else
    {
        m++;
        b[m]=a[i+1];
    }
    cout<<(m+1)-n<<endl;
    cout<<a[1]<<" ";
    for (int i=1; i<=m; i++)
        cout<<b[i]<<" ";
    cout<<endl;
}