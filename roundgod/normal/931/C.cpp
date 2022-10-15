#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],cnt1,cnt2,cnt3;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	if(a[n-1]-a[0]<2)
	{
		printf("%d\n",n);
		for(int i=0;i<n;i++)
			printf("%d ",a[i]);
		return 0;
	}
	cnt1=cnt2=cnt3=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==a[0]) cnt1++;
		else if(a[i]==a[n-1]) cnt3++;
		else cnt2++;
	}
	int ans=n;
	if((cnt2/2)*2>2*min(cnt1,cnt3))
	{
		ans-=(cnt2/2)*2;
		cnt1+=cnt2/2;
		cnt3+=cnt2/2;
		cnt2-=(cnt2/2)*2;
	}
	else
	{
		int res=min(cnt1,cnt3);
		ans-=2*res;
		cnt1-=res;
		cnt3-=res;
		cnt2+=2*res;
	}
	printf("%d\n",ans);
	for(int i=0;i<cnt1;i++)
		printf("%d ",a[0]);
	for(int i=0;i<cnt2;i++)
		printf("%d ",a[0]+1);
	for(int i=0;i<cnt3;i++)
		printf("%d ",a[0]+2);
	return 0;
}