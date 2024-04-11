/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=1100;
int n,a[N],b[N],w;
vector <int> p[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
signed main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),b[++w]=a[i];
	sort(b+1,b+1+w);w=unique(b+1,b+1+w)-b-1;
	for (int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+1+w,a[i])-b;
	// for (int i=1;i<=n;i++) printf("%d ",a[i]);
	// printf("\n");
	for (int i=1;i<=n;i++) p[a[i]].push_back(i);
	vector <pair<int,int> > ans;
	for (int i=1;i<=w;i++)
	{
		// reverse(p[i].begin(),p[i].end());
		for (int x:p[i])
		{
			for (int j=n;j>x;j--) if (a[j]<a[x]) ans.emplace_back(x,j);
		}
	}
	printf("%d\n",len(ans));
	for (auto [x,y]:ans) printf("%d %d\n",x,y),swap(a[x],a[y]);
	// for (int i=1;i<=n;i++) printf("%d ",a[i]);
	// printf("\n");
	for (int i=1;i<n;i++) assert(a[i]<=a[i+1]);
}