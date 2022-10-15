#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],ans[MAXN];
int vis[MAXN];
int find(int x)
{
	memset(vis,0,sizeof(vis));
	int flag=1,cnt=0;
	for(int i=0;i<n;i++)
	{
		if(vis[a[i]]==flag) continue;
		vis[a[i]]=flag;
		cnt++;
		if(cnt>x)
		{
			flag++;
			cnt=1;
			vis[a[i]]=flag;
		}
	}
	return flag;
}
void solve(int l,int r)
{
	if(l>r) return;
	int res1=find(l),res2=find(r);
	if(res1==res2)
	{
		for(int i=l;i<=r;i++) ans[i]=res1;
		return;
	}
	int mid=(l+r)/2;
	solve(l,mid);
	solve(mid+1,r);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	solve(1,n);
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}