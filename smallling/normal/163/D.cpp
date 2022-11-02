#include<cmath>
#include<cstdio>
#include<climits>
#include<algorithm>

using namespace std;

long long ans,V,la,lb,lc,lastans;
int n,t;
long long a[110],p[110];

void dfs(int A,int now,long long B)
{
	if(B*B>V/A)return;
	if(now>n)
	{
		if(B<A||B>V/A/B)return;
		lastans=ans;
		ans=min(ans,A*B+V/A+V/B);
		if(ans!=lastans)la=A,lb=B,lc=V/A/B;
		return;
	}
	if(p[now])p[now]--,dfs(A,now,B*a[now]),p[now]++;
	dfs(A,now+1,B);
}

void dfs(int now,int A)
{
	if(1ll*A*A*A>V)return;
	if(now>n)
	{
		if(2.*A*sqrt(V/A)+1.*V/A<ans)dfs(A,1,1);
		return;
	}
	if(p[now])p[now]--,dfs(now,A*a[now]),p[now]++;
	dfs(now+1,A);
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		V=1ll;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%I64d%I64d",&a[i],&p[i]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=p[i];j++)
				V=V*a[i];
		ans=LLONG_MAX;
		dfs(1,1);
		printf("%I64d %I64d %I64d %I64d\n",2ll*ans,la,lb,lc);
	}
}