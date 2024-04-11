 /*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=75,M=2*1e6+100,lim=1e6;
int T,n,a[N],b[N],cnt[M],ti[M],dfn;
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
pair<int,int> mk(int a,int b)
{
	int g=__gcd(a,b);
	a/=g;b/=g;
	return m_k(a,b);
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		vector <pair<int,int> > ok;
		for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) ok.push_back(mk(a[j]-a[i],j-i));
		sort(ok.begin(),ok.end());ok.resize(unique(ok.begin(),ok.end())-ok.begin());
		int MAX=1;
		for (auto [x,y]:ok)
		{
			for (int i=1;i<=n;i++) b[i]=a[i]*y-x*i;
			dfn++;
			for (int i=1;i<=n;i++)
			{
				int x=b[i]+lim;
				if (ti[x]!=dfn) ti[x]=dfn,cnt[x]=0;
				cnt[x]++;
			}
			for (int i=1;i<=n;i++) MAX=max(MAX,cnt[b[i]+lim]);
		}
		printf("%d\n",n-MAX);
	}
}