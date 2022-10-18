#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define write(x) wt(x),putchar(10)
#define pos(x) (((x)-1)/SZ+1)
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int N=55;
const int SZ=550;
const double eps=1e-9;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void wt(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}

int m;

struct Mat{int e[N][N];int* operator [](int p){return e[p];}void clear(){memset(e,0,sizeof(e));}void init(){clear();for (int i=0;i<=m;i++) e[i][i]=1;}};
Mat operator + (Mat a,Mat b){Mat c;for (int i=0;i<=m;i++) for (int j=0;j<=m;j++) c[i][j]=(a[i][j]+b[i][j])%mod;return c;}
Mat operator * (Mat a,Mat b){Mat c;for (int i=0;i<=m;i++) for (int j=0;j<=m;j++) c[i][j]=0;for (int k=0;k<=m;k++) for (int i=0;i<=m;i++) if (a[i][k]) for (int j=0;j<=m;j++) c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mod;return c;}
Mat ksm(Mat x,int y){Mat ret;ret.init();while (y){if (y&1) ret=ret*x;x=x*x;y>>=1;}return ret;}

int n,x,ans,res,s,k;
int a[N],l[N],r[N],d[N*6];
Mat A,B;
void solve(int L,int R)
{
	m=k=0;
	for(int i=L,t=s;i<=R;t+=a[i],i++)
	{
		l[++m]=(a[i]>0)?t+1:t-1;r[m]=t+a[i];if(m==1) l[1]=s;
		d[++k]=l[m],d[++k]=l[m]-1,d[++k]=l[m]+1;
		d[++k]=r[m],d[++k]=r[m]-1,d[++k]=r[m]+1;
	}
	sort(d+1,d+1+k);k=unique(d+1,d+1+k)-d-1;
	A.clear();A[0][0]=1;
	for(int i=1,ls=s-1;i<=k;i++)
	{
		B.clear();
		if(d[i]<=ls || d[i]>s+ans) continue;
		for (int j=1;j<=m;j++) if(min(l[j],r[j])<=ls+1 && max(l[j],r[j])>=d[i])
		{
			for (int k=0;k<=j;k++) B[k][j]=1;
			if(l[j]>=r[j]) B[j][j]=0;
		}
		A=A*ksm(B,d[i]-ls);ls=d[i];
	}
	for(int i=0;i<=m;i++) res=(res+A[0][i])%mod;
}
signed main()
{
	rd(n);rd(x);
    for (int i=1;i<=n;i++) {rd(a[i]);if (a[i]==0){i--;n--;continue;}}
    for (int i=1;i<=n;s+=a[i],i++) for (int j=i,t=s;j<=n;j++) t+=a[j],ans=max(ans,t-s);
	if (!ans){cout<<"1 "<<(-s+1)%mod<<endl;return 0;}
	s=0;for(int i=1;i<=n;s+=a[i],i++){int r=-1;for (int j=i,t=s;j<=n;j++){t+=a[j];if(t-s==ans) r=j;}if (r>0) solve(i,r),i=r;}
    cout<<ans+1<<" "<<res<<endl;
}
/*

*/