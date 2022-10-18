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
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int t=0;
    for (int j=1; j<=k; j++)
    {
        int l,r;
        cin>>l>>r;
        if (l==1)
        {
            if (t<m) {t++; b[t]=r; c[t]=a[r];} else
                {
                    int p=1;
                    for (int i=1; i<=m; i++)
                    if (c[i]<c[p]) p=i;
                    if (c[p]<a[r])
                    {
                        c[p]=a[r];
                        b[p]=r;
                    }
                }
        } else
        {
            int p=0;
            for (int i=1; i<=t; i++)
            if (b[i]==r) p=1;
            if (p==1) cout<<"YES"<<endl; else cout<<"NO"<<endl;
        }
    }
}