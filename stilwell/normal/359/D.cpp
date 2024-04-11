#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int a[1000001];
int n,i,j,k,ll,rr,len,Ans,Anss;
int ansl[1000001],ansr[1000001];
int ans[1000001];

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=1;i<=n;++i)ansl[i]=ansr[i]=i;
	for(i=1;i<=n;++i)
	while(ansl[i]>1&&a[ansl[i]-1]%a[i]==0)
	ansl[i]=ansl[ansl[i]-1];
	for(i=n;i>=1;--i)
	while(ansr[i]<n&&a[ansr[i]+1]%a[i]==0)
	ansr[i]=ansr[ansr[i]+1];
	for(i=1;i<=n;++i)
	{
		ll=ansl[i];
		rr=ansr[i];
		if(rr-ll==len)
		{
			++Ans;
			ans[Ans]=ll;
		}
		if(rr-ll>len)
		{
			len=rr-ll;
			ans[1]=ll;
			Ans=1;
		}
	}
	sort(ans+1,ans+Ans+1);
	for(i=1;i<=Ans;++i)
	if(ans[i]!=ans[i-1])++Anss;
	printf("%d %d\n",Anss,len);
	printf("%d",ans[1]);
	for(i=2;i<=Ans;++i)if(ans[i]!=ans[i-1])printf(" %d",ans[i]);
	printf("\n");
	//system("pause");
}