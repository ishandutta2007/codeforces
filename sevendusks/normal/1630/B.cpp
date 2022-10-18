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
int T,n,k,a[N],b[N];
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
		n=read();k=read();
		for (int i=1;i<=n;i++) a[i]=read(),b[i]=a[i];
		sort(b+1,b+1+n);
		int MIN=inf,x,y,now=(n+k+1)/2;
		for (int i=1;i<=n-now+1;i++) if (b[i+now-1]-b[i]<MIN)
		{
			MIN=b[i+now-1]-b[i];
			x=b[i];y=b[i+now-1];
		}
		printf("%d %d\n",x,y);
		vector <pair<int,int> > ans;
		for (int l=1,r;l<=n;l=r+1)
		{
			int sum=0;
			r=l;
			while (r<=n)
			{
				sum+=(a[r]>=x&&a[r]<=y)?1:-1;
				if (sum==1)
				{
					ans.emplace_back(l,r);
					break;
				}
				r++;
			}
		}
		while (len(ans)>k) ans.pop_back();
		ans.back().second=n;
		for (auto [x,y]:ans) printf("%d %d\n",x,y);
	}
}