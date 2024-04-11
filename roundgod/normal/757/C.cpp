#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 1000005
#define INF 1000000000
#define MOD 1000000007
#define MOD1 1000000009
#define MOD2 998244353
#define K 233
#define M 10007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,fact[MAXM],a[MAXM],cnt[MAXM];
vector<P> pk[MAXM];
bool cmp(vector<P> &x,vector<P> &y)
{
	if(x.size()!=y.size()) return x.size()<y.size();
	for(int i=0;i<x.size();i++)
		if(x[i]!=y[i]) return x[i]<y[i];
	return x.size()<y.size();
}
bool same(int x,int y)
{
	if(pk[x].size()!=pk[y].size()) return false;
	for(int i=0;i<pk[x].size();i++)
		if(pk[x][i]!=pk[y][i]) return false;
	return true;
}
int main()
{
	scanf("%d%d",&n,&m);
	fact[0]=1;
	for(int i=1;i<=m;i++)
		fact[i]=1LL*fact[i-1]*i%MOD;
	vector<int> save;
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		save.clear();
		for(int j=0;j<x;j++)
		{
			scanf("%d",&a[j]);
			cnt[a[j]]++;
			if(cnt[a[j]]==1) save.push_back(a[j]);
		}
		for(int j=0;j<save.size();j++)
			pk[save[j]].push_back(P(i,cnt[save[j]]));
		for(int j=0;j<x;j++)
			cnt[a[j]]--;
	}
	sort(pk+1,pk+m+1,cmp);
	int ans=1,cntt=1;
	for(int i=2;i<=m;i++)
	{
		if(same(i,i-1)) cntt++;
		else {ans=1LL*ans*fact[cntt]%MOD; cntt=1;}
	}
	ans=1LL*ans*fact[cntt]%MOD;
	printf("%d\n",ans);
	return 0;
}