/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=310,M=1e5+100;
int t,n,m,a[N][N];
struct node
{
	int v,id;
}sh[M];
bool cmp(node a,node b){return a.v<b.v||(a.v==b.v&&a.id>b.id);}
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
inline int id(int x){return (x-1)/m+1;}
void solve(int l,int r)
{
	static int L[M],R[M],w,kind[M];
	w=0;
	for (int i=l;i<=r;)
	{
		int j=i;
		while (j<=r&&id(i)==id(j)) j++;
		L[++w]=i;R[w]=j-1;kind[w]=id(i);
		i=j;
	}
	if (w==1)
	{
		for (int i=l;i<=r;i++) a[id(i)][(i-1)%m+1]=sh[i].id;
		return;
	}
	int tmp=R[1]-L[1]+1;
	for (int i=L[1],j=r-tmp+1;i<=R[1];i++,j++) a[id(i)][(i-1)%m+1]=sh[j].id;
	for (int i=L[w],j=l;i<=R[w];i++,j++) a[id(i)][(i-1)%m+1]=sh[j].id;
	for (int i=2;i<w;i++) for (int j=L[i];j<=R[i];j++) a[id(j)][(j-1)%m+1]=sh[j].id;
}
signed main()
{
	t=read();
	while (t--)
	{
		n=read();m=read();int w=n*m;
		for (int i=1;i<=w;i++) sh[i]=(node){read(),i};
		sort(sh+1,sh+1+w,cmp);
		for (int i=1;i<=w;)
		{
			int j=i;
			while(j<=w&&sh[i].v==sh[j].v) j++;
			solve(i,j-1);
			i=j;
		}
		int ans=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++) for (int k=1;k<j;k++) if (a[i][j]>a[i][k]) ans++;
		}
		printf("%d\n",ans);
	}
}