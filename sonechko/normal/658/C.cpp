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
int a[N],b[N],c[N];
int main()
{
    sync;
    int n,m,k;
    cin>>n>>m>>k;
    if (m==1&&k==1&&n!=2) {cout<<-1<<endl; return 0;}
    if (m==k&&n!=m+1)
    {
        int p=1;
        for (int i=1; i<=k; i++)
        {
            cout<<p<<" "<<p+1<<endl;
            p++;
        }
        for (int i=p+1; i<=n; i++)
            cout<<p-1<<" "<<i<<endl;
            return 0;
    }
    if (m-k>k) {cout<<-1<<endl; return 0;}
    //cout<<'!'<<endl;
    if (n-k-1<m-k) {cout<<-1<<endl; return 0;}
    int p=1;
    for (int i=1; i<=k; i++)
    {
        cout<<p<<" "<<p+1<<endl;
        p++;
    }
    int t=1;
    for (int i=p+1; i<=p+m-k; i++)
    {
        cout<<t<<" "<<i<<endl;
        t=i;
    }
    for (int i=p+m-k+1; i<=n; i++)
        cout<<"1 "<<i<<endl;
}