#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int n,d,a[MAXN];
int main()
{
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int res=n;
	for(int i=1;i<=n;i++)
	{
		int cnt=i-1;
		for(int j=i+1;j<=n;j++)
			if(max(a[i]-a[j],a[j]-a[i])>d) cnt++;
		res=min(res,cnt);
	}
	printf("%d\n",res);
	return 0;
}