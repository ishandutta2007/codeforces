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
int T,n,a[N],last[N],t[N];
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
	T=read();
	while (T--)
	{
		n=read();
		fill(last,last+n+10,-1);
		for (int i=1;i<=n;i++) a[i]=read(),last[a[i]]=i;
		vector <int> ans;
		for (int i=1;i<=n;i++)
		{
			int j=i,now=0;
			for (;j<=n;j++)
			{
				t[a[j]]=1;
				while (t[now]) now++;
				if (last[now]<=j) break;
			}
			for (int k=i;k<=j;k++) t[a[k]]=0;
			i=j;ans.push_back(now);
		}
		printf("%d\n",len(ans));
		for (int i:ans) printf("%d ",i);
		printf("\n");
	}	
}