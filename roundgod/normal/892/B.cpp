#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],cnt[MAXN],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		cnt[max(1,i-a[i])]++;
		cnt[i]--;
	}
	for(int i=1;i<=n;i++)
		cnt[i]+=cnt[i-1];
	for(int i=1;i<=n;i++)
		if(cnt[i]==0) ans++;
	printf("%d\n",ans);
	return 0;
}