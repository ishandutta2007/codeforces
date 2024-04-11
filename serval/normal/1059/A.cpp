#include <cstdio>
using namespace std;
const int N=100005;
int n,l,a,i,ans;
int s[N],t[N];
int main()
{
	scanf("%d%d%d",&n,&l,&a);
	for (i=1;i<=n;i++)
	{
		scanf("%d%d",&s[i],&t[i]);
		t[i]+=s[i];
	}
	ans+=s[1]/a;
	for (i=2;i<=n;i++)
		ans+=(s[i]-t[i-1])/a;
	ans+=(l-t[n])/a;
	printf("%d\n",ans);
	return 0;
}