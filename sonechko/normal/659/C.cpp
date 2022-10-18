#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 1000000;
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
int a[N],b[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int ans=0;
    int k=1;
    for (int l=1; l<=1000000000; l++)
        if (a[k]==l) k++; else
    {
        if (l>m) break;
        m-=l;
        ans++;
        b[ans]=l;
    }
    cout<<ans<<endl;
    for (int i=1; i<=ans; i++)
        cout<<b[i]<<" ";
    cout<<endl;
}