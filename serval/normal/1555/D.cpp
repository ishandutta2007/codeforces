#include <cstdio>
#include <algorithm>
using namespace std;
const int N=2e5+5;
int n,m;
char s[N];
int a[6][N],l,r;
int ans;
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<6;j++)
			a[j][i]=a[j][i-1];
		a[(s[i]-'a'+3*n-i)%3][i]++;
		a[('c'-s[i]+3*n-i)%3+3][i]++;
	}
	while (m--)
	{
		scanf("%d%d",&l,&r);
		ans=r-l+1;
		for (int i=0;i<6;i++)
			ans=min(ans,r-l+1-a[i][r]+a[i][l-1]);
		printf("%d\n",ans);
	}
	return 0;
}