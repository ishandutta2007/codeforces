#include<cstdio>
#include<algorithm>

using namespace std;

int i,j,k,l,m,n,o,p,a[101],b[101],ans;

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
	if(!b[i])
	{
		ans++;
		b[i]=1;
		o=1;
		for(j=i+1;j<=n;j++)
		if(a[j]>=o&&!b[j])
		{
			o++;
			b[j]=1;
		}
	}
	printf("%d",ans);
}