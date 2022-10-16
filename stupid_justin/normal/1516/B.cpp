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
int n,m,q,la,l,r;
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
	   rd(n);
			for (int i=1;i<=n;i++) rd(a[i]);
	   if (n==2) {if (a[1]==a[2]) puts("YES");else puts("NO");}
	   else 
	   {
			bool flag=0;
			for (int i=1;i<=n;i++) b[i]=b[i-1]^a[i];
			for (int i=1;i<=n-1;i++)
			{
				if (b[i]==(b[n]^b[i])) flag=1;
			}
			for (int i=1;i<=n-2;i++) for (int j=i+1;j<=n-1;j++)
			{
				if (b[i]==(b[n]^b[j]) && b[i]==(b[j]^b[i])) flag=1;
			}
			if (flag) puts("YES");else puts("NO");
	   }
		
   }
}