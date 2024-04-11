
#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
using namespace std;
const int N=3e4+5;
int read(){int x=0,f=1;char ch=getchar();while (ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int n,C,q;
int a[N],st[10];
int x,t;
int L[10][N],R[10][N],f[10][N];
bool cmp(int i,int j){return a[x+i]<a[x+j];}
int F(int x,int c,int rk)
{
    int l=x,r=n,ret=0;
	while (l<=r)
    {
		int mid=(l+r)>>1;
		if (L[c][x]-L[c][mid]<rk && R[c][x]-R[c][mid]<=f[c][x]-rk) 
        l=mid+1,ret=mid;else r=mid-1;
	}
    return ret;
}
int query(int p,int rk)
{
	if (rk>f[C][1]) return -1;
	int c=C;x=1;
	while (x<=n)
    {
		int res=F(x,c,rk);if (res>p) return a[p];
		rk-=(L[c][x]-L[c][res]),x=res,t=0;
		for (int i=0;i<=c && x+i<=n;i++) st[++t]=i;
		sort(st+1,st+t+1,cmp);int l=0;
		for (int i=1;i<=t;i++) if (rk<=f[c-st[i]][x+st[i]+1]){l=st[i];break;}else rk-=f[c-st[i]][x+st[i]+1];
		if (l+x>=p) return a[2*x-p+l];c-=l,x+=l+1;
	}
	return a[p];
}
void init()
{
    for (int k=0;k<=C;k++)
    {
		f[k][n+1]=1,L[k][n+1]=R[k][n+1]=0;
		for (int i=n;i>=1;i--)
        {
			f[k][i]=f[k][i+1],L[k][i]=L[k][i+1],R[k][i]=R[k][i+1];
			for (int j=1;j<=k && j<=n-i;j++)
            {
				int v=f[k-j][i+j+1];f[k][i]+=v;
				if (a[i]>a[i+j]) L[k][i]+=v;else R[k][i]+=v;
			}
		}
	}
}
void DOIT()
{
	rd(n);rd(C);rd(q);for (int i=1;i<=n;i++) rd(a[i]);
    init();while (q--){int i,j;rd(i);rd(j);cout<<query(i,j)<<"\n";}
}
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--) DOIT();
}
/*

*/