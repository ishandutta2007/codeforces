#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 1004;
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
int n,a[N],score[N],sc[N],m,ans;
string st[N],t[N];
int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        {
            cin>>st[i]>>a[i];
            int k=0;
            for (int j=1; j<=m; j++)
            if (st[i]==t[j]) {k=1; score[j]+=a[i]; break;}
            if (k==0) {m++; t[m]=st[i]; score[m]=a[i];}
        }
    ans=-100000000;
    for (int i=1; i<=m; i++)
    ans=max(ans,score[i]);
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
    if (st[i]==t[j]) {sc[j]+=a[i]; if (sc[j]>=ans&&score[j]==ans) {cout<<t[j]<<endl; return 0;} }
}