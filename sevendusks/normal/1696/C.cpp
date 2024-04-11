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
const int N=2*1e5+100;
int T,n,m,k,a[N],b[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
void work(vector <pair<int,int> > &sh,int a[],int n)
{
	static int c[N],d[N];
	for (int i=1;i<=n;i++)
	{
		c[i]=a[i];d[i]=1;
		while (c[i]%m==0) c[i]/=m,d[i]*=m;
	}
	for (int i=1;i<=n;)
	{
		int j=i,sum=0;
		while (j<=n&&c[i]==c[j]) sum+=d[j++];
		sh.emplace_back(c[i],sum);
		i=j;
	}
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();m=read();
		for (int i=1;i<=n;i++) a[i]=read();
		k=read();
		for (int i=1;i<=k;i++) b[i]=read();
		vector <pair<int,int> > A,B;
		work(A,a,n);work(B,b,k);
		if (A==B) printf("Yes\n");
		else printf("No\n");
	}
}