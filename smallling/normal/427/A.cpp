#include<cstdio>

using namespace std;

int n,m,ans,o;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&o);
		if(o>0)m+=o;
		else 
		if(m>0)m--;
		else ans++;
	}
	printf("%d",ans);
}