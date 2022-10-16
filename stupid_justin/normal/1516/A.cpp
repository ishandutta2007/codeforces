#include<bits/stdc++.h>
#define int long long
#define ri register signed
#define rd(x) x=read()
using namespace std;
const int N=5e5+5;
const int M=805;
const int mod=998244353;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int sz;
int n,m,k,q,la,l,r;
int a[N],b[N],pos[N],L[N],R[N],bel[N],cnt[N];
int mx[M][M];
vector<int> p[N];
int solve(int len,int x)
{
	if (x<=(len+1)/2) return 1;
	int t=len-x;
	len-=2*t+1;
	return len+1;
}
signed main()
{
   int T;cin>>T;while (T--)
   {
	   rd(n);rd(k);
	   for (int i=1;i<=n;i++) rd(a[i]);
	   for (int i=1;i<n;i++)
	   {
		   if (k>=a[i]) k-=a[i],a[n]+=a[i],a[i]=0;
		   if (k<a[i]) a[i]-=k,a[n]+=k,k=0;
	   }
	   for (int i=1;i<=n;i++) cout<<a[i]<<" ";
	   cout<<endl;
   }
}