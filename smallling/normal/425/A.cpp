#include<cstdio>
#include<algorithm>

using namespace std;

int n,k,a[201],c[201],d[201],o,sum,ans,sum1,sum2;

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	ans=-1000000000;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			sum=0;
			sum2=0;
			sum1=0;
			o=0;
			for(int i1=i;i1<=j;i1++)
				c[++sum2]=a[i1],sum+=a[i1];
			for(int i1=j+1;i1<=n;i1++)
				d[++sum1]=a[i1];
			for(int i1=1;i1<i;i1++)
				d[++sum1]=a[i1];
			sort(c+1,c+1+sum2);
			sort(d+1,d+1+sum1);
			for(int i1=1;i1<=sum2;i1++)
			{
				if(sum1-i1+1<=0)break;
				if(c[i1]<d[sum1-i1+1])sum+=d[sum1-i1+1]-c[i1],o++;
				if(o==k)break;
			}
			ans=max(ans,sum);
		}
	printf("%d\n",ans);
}