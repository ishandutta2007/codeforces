#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 200000;
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
#define next isehfejrb
int a[N],b[N];
int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int j=1; j<=n; j++)
        cin>>b[j];
    int ans1=0,ans2=0,k=0;
    for (int i=1; i<=n; i++)
    {
        k+=b[i];
        ans1+=max(0,a[i]-m*k);
    }
    k=0;
    for (int i=n; i>=1; i--)
    {
        k+=b[i];
        ans2+=max(0,a[i]-m*k);
    }
    if (ans1>ans2) cout<<"Limak"<<endl; else
    if (ans2>ans1) cout<<"Radewoosh"<<endl; else cout<<"Tie"<<endl;
}