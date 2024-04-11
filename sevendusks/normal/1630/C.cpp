/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=2*1e5+100;
int n,a[N],first[N],last[N],w,vi[N];
struct node
{
	int l,r;
}sh[N];
node b[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
int solve(int l,int r)
{
	if (l==r) return 1;
	int last=b[l].r,cnt=1;
	for (int i=l+1;i<r;i++)
	{
		if (b[i+1].l>last)
		{
			last=b[i].r;cnt++;
		}
	}
	return cnt+1;
}
signed main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),last[a[i]]=i;
	for (int i=n;i>=1;i--) first[a[i]]=i;
	for (int i=1;i<=n;i++) if (first[i]!=last[i]) sh[++w]=(node){first[i],last[i]};
	sort(sh+1,sh+1+w,[](node a,node b){return a.l<b.l;});
	int MAX=0;
	for (int i=1;i<=w;i++)
	{
		if (MAX>sh[i].r) vi[i]=1;
		MAX=max(MAX,sh[i].r);
	}
	int cnt=0;
	for (int i=1;i<=w;i++) if (!vi[i]) b[++cnt]=sh[i];
	int ans=0;
	for (int i=1;i<=cnt;)
	{
		int j=i+1;
		while (j<=cnt&&b[j].l<=b[j-1].r) j++;
		ans+=b[j-1].r-b[i].l+1;
		ans-=1+solve(i,j-1);
		i=j;
	}
	printf("%d\n",ans);
}