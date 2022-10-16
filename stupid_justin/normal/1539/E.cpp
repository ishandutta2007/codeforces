#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
#define pos(x) (((x)-1)/SZ+1)
using namespace std;
const int N=1e6+5;
const int M=70;
const int SZ=450;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int n,m,ans;
int al[N],bl[N],ar[N],br[N],k[N];
int l,r,L,R,lp,rp;
int lmin,rmin,lmax,rmax;
int tr[N][2];
//f[0/1][i][j] 
set<pii> S[2];

signed main()
{
    rd(n);rd(m);
    lp=rp=n+1;l=r=1;lmin=rmin=0;lmax=rmax=m;
    for (int i=1;i<=n;i++) rd(k[i]),rd(al[i]),rd(bl[i]),rd(ar[i]),rd(br[i]);
    for (int i=n;i>=1;i--)
    {
        if (k[i]<al[i] || k[i]>bl[i]) l=0;if (k[i]<ar[i] || k[i]>br[i]) r=0;
        lmin=max(lmin,ar[i]);lmax=min(lmax,br[i]);rmin=max(rmin,al[i]);rmax=min(rmax,bl[i]);
		L=(l && k[i-1]>=lmin && k[i-1]<=lmax);R=(r && k[i-1]>=rmin && k[i-1]<=rmax);
        if(L) tr[i][0]=rp;if(R) tr[i][1]=lp;
		if(L) lp=i,r=1,rmin=0,rmax=m;if(R) rp=i,l=1,lmin=0,lmax=m;
    }
    if (lp>1 && rp>1) {puts("No");return 0;}
    puts("Yes");
    bool t=0;if (lp>1) t=1;
    for(int i=1;i<=n;i=tr[i][t],t^=1) for(int j=i;j<tr[i][t];j++) cout<<t<<" ";cout<<endl;
}