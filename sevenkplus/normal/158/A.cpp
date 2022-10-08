#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,S,a[55];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1,a+n+1),reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++)if(a[i]>=a[m]&&a[i])S++;
	printf("%d\n",S);
	return 0;
}