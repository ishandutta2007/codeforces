#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int M = 500001;
const int N = 300000;
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
#define next isehfejrbw
int g[1600006];
void updatesum(int i, int l, int r, int x, int t)
{
    if (l==r) {g[i]=t; return;}
    int d=(l+r)/2;
    if (x<=d) updatesum(2*i,l,d,x,t); else updatesum(2*i+1,d+1,r,x,t);
    g[i]=g[i*2]+g[i*2+1];
}
int sumi(int i, int l, int r, int tl, int tr)
{
    if (tl>r||l>tr) return 0;
    if (tl<=l&&r<=tr) return g[i];
    int d=(l+r)/2;
    return sumi(2*i,l,d,tl,tr)+sumi(2*i+1,d+1,r,tl,tr);
}
int tin[N],ans[N];
int main()
{
    sync;
    int n;
    cin>>n;
    int m=0;
    pair<int,int> a[n*2+2];
    int x[n+1],y[n+1];
    for (int i=1; i<=n; i++)
    {
        cin>>x[i]>>y[i];
        m++;
        a[m].f=x[i];
        a[m].s=i;
        m++;
        a[m].f=y[i];
        a[m].s=i;
    }
    sort(a+1,a+m+1);
    for (int i=1; i<=m; i++)
    {
        int l=a[i].s;
        if (x[l]==a[i].f)
        {
            tin[l]=i;
        } else
        {
            ans[l]=sumi(1,1,m,tin[l],i);
            updatesum(1,1,m,tin[l],1);
        }
    }
    for (int i=1; i<=n; i++)
        cout<<ans[i]<<endl;
}