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
const int N=4*1e6+100;
int n,mod,f[N],sum[N];
inline void add(int &a,int b){a=((a+b>=mod)?a+b-mod:a+b);}
inline void del(int &a,int b){a=((a-b<0)?a-b+mod:a-b);}
inline void mul(int &a,int b){a=a*b%mod;}
inline int m_pow(int a,int b)
{
	int ans=1;
	while (b)
	{
		if (b&1) mul(ans,a);
		b>>=1;
		mul(a,a);
	}
	return ans;
}
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
signed main()
{
	n=read();mod=read();
	f[n]=1;sum[n]=1;
	for (int i=n-1;i>=1;i--)
	{
		f[i]=sum[i+1];
		for (int j=2;j<=n/i;j++)
		{
			int k=i*j;
			add(f[i],sum[k]);
			if (k+j<=n) del(f[i],sum[k+j]);
		}
		sum[i]=sum[i+1];add(sum[i],f[i]);
	}
	printf("%lld\n",f[1]);
}