/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=(1<<17);
int T,n,k,vi[N];
vector <pair<int,int> > ans;
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
void solve(int a,int b,int k)
{
	if (k==-1)
	{
		assert((a&b)==0);
		ans.emplace_back(a,b);
		return;
	}
	solve(a|(1<<k),b,k-1);
	solve(a,b|(1<<k),k-1);
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();k=read();
		for (int i=0;i<n;i++) vi[i]=0;
		if (k==n-1)
		{
			if (n==4)
			{
				printf("-1\n");
				continue;
			}
			for(int i=0;i<n/2-4;i++) printf("%d %d\n",i,n-1-i);
			int now=n/2;
			printf("%d %d\n",now,now+3);
			printf("%d %d\n",now-4,now-1);
			printf("%d %d\n",now-3,now+1);
			printf("%d %d\n",now-2,now+2);
			continue;
		}
		int p=log(n)/log(2);p--;
		ans.clear();
		solve(1<<p,0,p-1);
		if (k!=0)
		{
			int A=0,B=0;
			for (int i=0;i<len(ans);i++)
			{
				if (ans[i].first==n-1||ans[i].second==n-1) A=i;
				if (ans[i].first==k||ans[i].second==k) B=i;
			}
			assert(A!=B);
			if (ans[A].first!=n-1) swap(ans[A].first,ans[A].second);
			if (ans[B].first!=k) swap(ans[B].first,ans[B].second);
			swap(ans[A].second,ans[B].first);
		}
		int sum=0;
		for (auto [x,y]:ans) sum+=(x&y);
		assert(sum==k);
		for (auto [x,y]:ans) printf("%d %d\n",x,y);
	}
}