#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,cnt[MAXN],ans[MAXN],a[MAXN];
int main()
{
	scanf("%d%d",&n,&m);
	memset(cnt,0,sizeof(cnt));
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>m) continue; else cnt[a[i]]++;
	}
	for(int i=1;i<=m;i++)
		for(int j=i;j<=m;j+=i)
			ans[j]+=cnt[i];
	int res=-1,t=-1;
	for(int i=1;i<=m;i++)
		if(ans[i]>res) {res=ans[i]; t=i;}
	printf("%d %d\n",t,res);
	for(int i=1;i<=n;i++)
		if(t%a[i]==0) printf("%d ",i);
	return 0;
}