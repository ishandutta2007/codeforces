#include<bits/stdc++.h>
using namespace std;
const int N = 100 + 11;
const long long MOD = 1e9 + 7;
#define mod %MOD
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ss second
#define ff first
#define ll long long
#define mp make_pair
#define endl "\n"
#define pb push_back
#define y1 ijdj
#define next lzk
#define ld long double
#define sqr(a) ((a)*(a))
ll b[N];
struct matrix
{
    ll n,m;
    vector<vector<ll> > a;
    matrix(ll _n, ll _m)
    {
        n=_n;
        m=_m;
        vector<ll> x(m,0);
        vector<vector<ll> > _a(n,x);
        a=_a;
    }
    matrix operator*(matrix b)
    {
        matrix c(n,b.m);
        for (ll i=0; i<n; i++)
            for (ll j=0; j<b.m; j++)
        {
            ll s=0;
            for (ll k=0; k<m; k++)
                s=(s+a[i][k]*b.a[k][j])mod;
            c.a[i][j]=s;
        }
        return c;
    }
};
matrix step(matrix aa, ll x)
{
    if (x==1) return aa;
    if (x%2==1) return (aa*(step(aa,x-1)));
    matrix p=step(aa,x/2);
    return p*p;
}
int main()
{
    #ifdef LOCAL
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    sync;
    #endif
    ll n;
    long long m;
    cin>>n>>m;
    if (m==1) {cout<<n<<endl; return 0;}
    matrix c(n,n);
    for (ll i=1; i<=n; i++)
        cin>>b[i];
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++)
        {
            ll coun=0;
            ll p=(b[i]^b[j]);
            while (p)
            {
                coun+=(p%2);
                p/=2;
            }
            if (coun%3==0) c.a[i-1][j-1]=1; else
                c.a[i-1][j-1]=0;
        }
    matrix fu=step(c,m-1);
    ll coun=0;
    for (ll i=0; i<fu.n; i++)
        for (ll j=0; j<fu.m; j++)
        coun=(coun+fu.a[i][j])mod;

    cout<<coun<<endl;
}