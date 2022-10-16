#include <cstdio>
using namespace std;
int n,i;
int f[5005];
bool ans;
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d",&f[i]);
	for (i=1;i<=n;i++)
		if (f[f[f[i]]]==i)
			ans=1;
	printf(ans?"YES\n":"NO\n");
	return 0;
}