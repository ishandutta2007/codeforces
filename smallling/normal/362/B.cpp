#include<cstdio>
#include<algorithm>

using namespace std;

int i,j,k,l,m,n,o,p,a[4001];

int main()
{
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	if(a[1]==1||a[n]==m){printf("NO");return 0;}
	for(i=1;i<=n-2;i++)
	if((a[i+2]==(a[i+1]+1))&&(a[i+1]==a[i]+1))
	{
		printf("NO");
		return 0;
	}
	printf("YES");
}