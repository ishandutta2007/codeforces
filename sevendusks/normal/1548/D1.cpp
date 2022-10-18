/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=6100;
int n,x[N],y[N],s[N],sum[2][2];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
bool check(int i,int j){return ((x[i]&1)==(x[j]&1)&&(y[i]&1)==(y[j]&1));}
void upd(int i,int v)
{
	sum[x[i]&1][y[i]&1]+=v;
}
signed main()
{
	n=read();
	for (int i=1;i<=n;i++) x[i]=read()/2,y[i]=read()/2;
	for (int i=1;i<=n;i++) upd(i,1);
	long long ans=0;
	for (int i=1;i<=n;i++) for (int j=1;j<i;j++)
	{
		if (check(i,j)) ans+=n-2;
		else
		{
			upd(i,-1);upd(j,-1);
			for (int a=0;a<=1;a++)
			{
				for (int b=0;b<=1;b++)
				{
					x[n+1]=a;y[n+1]=b;
					if (check(i,n+1)!=check(j,n+1)) ans+=sum[a][b];
				}
			}
			upd(i,1);upd(j,1);
		}
	}
	assert(ans%3==0);
	ans/=3;
	printf("%lld\n",ans);
}