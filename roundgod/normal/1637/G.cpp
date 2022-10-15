#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int cnt[MAXN];
vector<P> ans;
void go(int x,int y)
{
	assert(cnt[x]); assert(cnt[y]);
	cnt[x]--; cnt[y]--;
	cnt[x+y]++; cnt[max(x-y,y-x)]++;
	ans.push_back(P(x,y));
}
void solve(int n,int mult)
{
	if(n<=2) return;
	int t=1;
	while(2*t<=n) t*=2;
	if(t==n) {solve(n-1,mult); return;}
	for(int i=t+1;i<=n;i++)
		go(i*mult,(2*t-i)*mult);
	solve(t-(n-t)-1,mult);
	solve(n-t,2*mult);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		ans.clear();
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++) cnt[i]=(i<=n?1:0);
		if(n==2) {puts("-1"); continue;}
		solve(n,1);
		int t=1;
		while(2*t<=n) t*=2;
		if(t==n) t/=2;
		for(int i=1;i<=t;i*=2)
		{
			if(cnt[i]>=2)
			{
				go(i,i);
				break;
			}
		}
		for(int i=1;i<=t;i*=2)
		{
			while(cnt[i]>=2) go(i,i);
			if(cnt[i])
			{
				go(i,0);
				go(i,i);
			}
		}
		t*=2;
		while(cnt[t]!=n) go(t,0);
		printf("%d\n",(int)ans.size());
		for(auto p:ans) printf("%d %d\n",p.F,p.S);
	}
	return 0;
}