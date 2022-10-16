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
   rd(n);rd(q);
   for (int i=1;i<=n;i++) rd(a[i]),b[i]=a[i];
   sort(b+1,b+n+1);m=unique(b+1,b+n+1)-b-1;
   for (int i=1;i<=n;i++) {a[i]=lower_bound(b+1,b+m+1,a[i])-b;}
   for (int i=1;i<=n;i++) pos[i]=p[a[i]].size(),p[a[i]].push_back(i);
   sz=sqrt(n);
   for (int i=1;i<=n;i++) bel[i]=(i-1)/sz+1;m=bel[n];
   for (int i=1;i<=m;i++) L[i]=R[i-1]+1,R[i]=i*sz;R[m]=n;
   for (int i=1;i<=m;i++)
   {
      memset(cnt,0,sizeof(cnt));
      for (int j=i;j<=m;j++)
      {
         mx[i][j]=mx[i][j-1];
         for (int k=L[j];k<=R[j];k++) cnt[a[k]]++,mx[i][j]=max(mx[i][j],cnt[a[k]]);
      }
   }
   while (q--)
   {
      rd(l);rd(r);la=0;
      if (bel[l]==bel[r])
      {
         for (int i=l;i<=r;i++) cnt[a[i]]=0;
         for (int i=l;i<=r;i++) cnt[a[i]]++,la=max(la,cnt[a[i]]);
      } else 
      {
         la=mx[bel[l]+1][bel[r]-1];
         for (int i=l;i<=R[bel[l]];i++){int x=pos[i];while (x+la<p[a[i]].size() && p[a[i]][x+la]<=r) la++;}
         for (int i=L[bel[r]];i<=r;i++){int x=pos[i];while (x-la>=0 && p[a[i]][x-la]>=l) la++;}
      }
      cout<<solve(r-l+1,la)<<'\n';
   }
}