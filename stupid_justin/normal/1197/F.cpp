#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
#define pos(x) (((x)-1)/SZ+1)
#define endl "\n"
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int N=1e6+5;
const int M=64;
const int mod=998244353;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}

void add(int &x,int y) {x+=y;if (x>=mod) x-=mod;}
int n,m,a[N],f[4][4],ans[N][4];
vector<pii> v[N];
struct Mat{int e[M][M];int* operator [](int p){return e[p];}}pw[M],col[4],tmp;
Mat operator + (Mat a,Mat b){Mat c;for (int i=0;i<M;i++) for (int j=0;j<M;j++) c[i][j]=(a[i][j]+b[i][j])%mod;return c;}
Mat operator * (Mat a,Mat b){Mat c;for (int i=0;i<M;i++) for (int j=0;j<M;j++) c[i][j]=0;for (int k=0;k<M;k++) for (int i=0;i<M;i++) if (a[i][k]) for (int j=0;j<M;j++) c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mod;return c;}
void ksm(Mat &x,int y){for (int i=0;i<=30;i++) if (y>>i&1) x=x*pw[i];}
int F(int c,int S){for (int i=0;i<=3;i++) if((!f[c][3] || (S&3^i)) && (!f[c][2] || (S>>2&3^i)) && (!f[c][1] || (S>>4^i))) return S>>2|i<<4;}

signed main()
{
    rd(n);for (int i=1;i<=n;i++) rd(a[i]);
    rd(m);for (int i=1,x,y,c;i<=m;i++) rd(x),rd(y),rd(c),v[x].push_back(mp(y,c));
    for (int i=1;i<=3;i++) for (int j=1;j<=3;j++) rd(f[i][j]);
    for (int i=1;i<=3;i++) for (int S=0;S<M;S++){int x=F(i,S);col[i][S][x]++;pw[0][S][x]++;}
    for (int i=1;i<=30;i++) pw[i]=pw[i-1]*pw[i-1];
    ans[0][0]=1;for (int i=1;i<=n;i++) sort(v[i].begin(),v[i].end());
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<M;j++) for (int k=0;k<M;k++) tmp[j][k]=0;tmp[0][63]=1;
        int la=1;for (pii p:v[i]) ksm(tmp,p.fi-la),tmp=tmp*col[p.se],la=p.fi+1;
        ksm(tmp,a[i]+1-la);for (int j=0;j<=3;j++) for (int S=0;S<M;S++) add(ans[i][j^(S>>4)],ans[i-1][j]*tmp[0][S]%mod);
    }
    cout<<ans[n][0]<<endl;
}