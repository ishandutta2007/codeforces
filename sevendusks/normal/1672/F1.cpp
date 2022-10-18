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
int T,n,a[N],ans[N],b[N];
vector <int> p[N],cir[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();
		for (int i=1;i<=n;i++) p[i].clear(),cir[i].clear();
		for (int i=1;i<=n;i++) a[i]=read(),p[a[i]].push_back(i);
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<len(p[i]);j++) cir[j+1].push_back(p[i][j]);
		}
		for (int i=1;i<=n;i++) if (!cir[i].empty())
		{
			cir[i].push_back(cir[i][0]);
			for (int j=0;j<len(cir[i])-1;j++) ans[cir[i][j]]=cir[i][j+1];
		}
		for (int i=1;i<=n;i++) b[ans[i]]=a[i];
		for (int i=1;i<=n;i++) printf("%d ",b[i]);
		printf("\n");
	}
}