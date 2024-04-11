 /*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=1e5+100;
int T,n,pa[N],pb[N],A[N],B[N],f[N];
struct node
{
	int v,id;
}a[N];
node b[N];
bool cmp(node a,node b){return a.v<b.v;}
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
bool check(int x,int mid)
{
	mid=max(mid,pb[x]);
	if (pa[mid]<=x) return 0;
	return f[pa[mid]]<=mid;
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();
		for (int i=1;i<=n;i++) a[i]=(node){read(),i};
		for (int i=1;i<=n;i++) b[i]=(node){read(),i};
		sort(a+1,a+1+n,cmp);sort(b+1,b+1+n,cmp);
		for (int i=1;i<=n;i++) A[a[i].id]=i,B[b[i].id]=i; 
		for (int i=1;i<=n;i++) pa[i]=max(pa[i-1],B[a[i].id]);
		for (int i=1;i<=n;i++) pb[i]=max(pb[i-1],A[b[i].id]);
		f[n]=1;
		for (int i=n-1;i>=1;i--)
		{
			int l=1,r=n;
			while (l<r)
			{
				int mid=(l+r)>>1;
				if (check(i,mid)) r=mid;
				else l=mid+1;
			}
			f[i]=r;
		}
		for (int i=1;i<=n;i++)
		{
			if (f[B[i]]<=A[i]) printf("1");
			else printf("0");
		}
		printf("\n");
	}
}