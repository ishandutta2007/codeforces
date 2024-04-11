#include <cstdio>
#include <algorithm>
using namespace std;
const int N=100005;
int n;
int v[N],last;
bool f[N];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	last=n;
	for (int i=1;i<=n;i++)
	{
		f[v[i]]=1;
		while (f[last])
		{
			printf("%d ",last);
			last--;
		}
		printf("\n");
	}
	return 0;
}