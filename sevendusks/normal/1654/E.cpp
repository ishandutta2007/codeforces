/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=2*1e5+100,M=1e6+100,D=5e5;
int n,a[N],ok[M],dfn;
vector <int> p[N];
inline void ckmin(int &a,int b){a=((a<b)?a:b);}
inline void ckmax(int &a,int b){a=((a>b)?a:b);}
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
	for (int i=1;i<=n;i++) a[i]=read(),p[a[i]].push_back(i);
	int MAX=*max_element(a+1,a+1+n),ans=0;
	for (int i=1;i<=MAX;i++) ans=max(ans,len(p[i]));
	int B=sqrt(MAX);
	for (int d=1;d<=B;d++)
	{
		for (int i=1;i<=d;i++)
		{
			for (int j=i,k=1;j<=MAX;j+=d,k++)
			{
				for (int pos:p[j]) ckmax(ans,++ok[k-pos+D]);
			}
			for (int j=i,k=1;j<=MAX;j+=d,k++)
			{
				for (int pos:p[j]) ok[k-pos+D]=0;
			}
			for (int j=i,k=1;j<=MAX;j+=d,k++)
			{
				for (int pos:p[j]) ckmax(ans,++ok[k+pos+D]);
			}
			for (int j=i,k=1;j<=MAX;j+=d,k++)
			{
				for (int pos:p[j]) ok[k+pos+D]=0;
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;(j-i-1)*B<=MAX&&j<=n;j++)
		{
			int A=a[j]-a[i],B=j-i;
			if (A%B==0) ckmax(ans,(++ok[A/B+D])+1);
		}
		for (int j=i+1;(j-i-1)*B<=MAX&&j<=n;j++)
		{
			int A=a[j]-a[i],B=j-i;
			ok[A/B+D]=0;
		}
	}
	printf("%d\n",n-ans);
}