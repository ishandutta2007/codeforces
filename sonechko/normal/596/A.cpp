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
int n,a[N],b[N],ans;
int main()
{
    sync;
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    cin>>a[i]>>b[i];
    if (n==1) {cout<<-1<<endl; return 0;}
    if (n==2&&(a[1]==a[2]||b[1]==b[2])) {cout<<-1<<endl; return 0;}
    int x1=INT_MAX,y1=INT_MAX;
    int x2=-INT_MAX,y2=-INT_MAX;
    for (int i=1; i<=n; i++)
    {
        x1=min(x1,a[i]);
        x2=max(x2,a[i]);
        y1=min(y1,b[i]);
        y2=max(y2,b[i]);
    }
    cout<<(y2-y1)*(x2-x1)<<endl;
}