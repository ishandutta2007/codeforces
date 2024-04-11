/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define int long long
#define len(a) (int)a.size()
using namespace std;
const int N=1e6+100;
int n,m,p[N],x[N],L[N],R[N],b[N<<1],w;
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
int solve(int wh)
{
	int tl=lower_bound(x+1,x+1+m,wh)-x-1,tr=lower_bound(x+1,x+1+m,wh)-x;
	if (x[tr]==wh) return 0;
	int L=1,R=n;
	if (tl>0)
	{
		int pos=(wh+x[tl])/2+1;
		L=(pos+199)/200+1;
	}
	if (tr!=m+1)
	{
		int pos=(wh+x[tr]-1)/2;
		R=pos/200+1;R=min(R,n);
	}
	if (L<=R) return p[R]-p[L-1];
	else return 0;
}
signed main()
{
	n=read();m=read();
	for (int i=1;i<=n;i++) p[i]=read()+p[i-1];
	for (int i=1;i<=m;i++) x[i]=read()*2;
	sort(x+1,x+1+m);
	for (int i=1;i<=n;i++)
	{
		int pos=(i-1)*200;
		R[i]=lower_bound(x+1,x+1+m,pos)-x;
		if (R[i]==m+1) R[i]=-1;
		L[i]=upper_bound(x+1,x+1+m,pos)-x-1;
		if (L[i]==0) L[i]=-1;
	}
	for (int i=1;i<=m;i++) b[++w]=x[i]-1,b[++w]=x[i]+1;
	for (int i=1;i<=n;i++)
	{
		int pos=(i-1)*200;
		if (L[i]!=-1&&x[L[i]]!=pos) b[++w]=pos+(pos-x[L[i]])-1;
		if (R[i]!=-1&&x[R[i]]!=pos) b[++w]=pos-(x[R[i]]-pos)+1;
	}
	sort(b+1,b+1+w);w=unique(b+1,b+1+w)-b-1;
	// for (int i=1;i<=w;i++) printf("%lld ",b[i]);
	// printf("\n");
	int MAX=0;
	for (int i=1;i<=w;i++) if (b[i]>=0) MAX=max(MAX,solve(b[i]));
	printf("%lld\n",MAX);
}