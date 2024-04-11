
#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define rd(x) x=read()
#define wt(x) write(x)
using namespace std;
const int N=200+5;
const int M=55;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int n,k,x[N],y[N];
pair<int,int>f[N][N];
int s(int i,int j,int k){return (x[j]-x[i])*(y[k]-y[i])-(y[j]-y[i])*(x[k]-x[i]);}
int solve(int x)
{
    for (int len=3;len<=n;len++) for (int l=1;l<=n-len+1;l++)
    {
        int r=l+len-1;f[l][r]={0,0};
        for (int k=l+1;k<r;k++)
        {
            int a=f[l][k].fi+f[k][r].fi;
            int b=f[l][k].se+f[k][r].se+s(l,k,r);
            if (b>=x) f[l][r]=max(f[l][r],mp(a+1,0LL));else f[l][r]=max(f[l][r],mp(a,b));
        }
    }
	return f[1][n].fi;
}
signed main()
{
    rd(n);rd(k);
    for (int i=1;i<=n;i++) rd(x[i]),rd(y[i]);
    int l=0,r=8e16,ans=0;
    while (l<=r){int mid=(l+r)/2;if (solve(mid)>k) ans=mid,l=mid+1;else r=mid-1;}
    cout<<ans<<endl;
}