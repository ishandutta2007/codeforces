#include<cstdio>
#include<algorithm>

#define mo 1000000007

using namespace std;

int n,ans;
int a[500050],P2[500050];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	P2[0]=1;
	for(int i=1;i<=n;i++)
		P2[i]=P2[i-1]*2%mo;
	for(int i=1;i<=n;i++)
	{
		ans-=1ll*a[i]*(P2[n-i]-1)%mo;
		if(ans<0)ans+=mo;
		ans+=1ll*a[i]*(P2[i-1]-1)%mo;
		if(ans>mo)ans-=mo;
	}
	printf("%d\n",ans);
}