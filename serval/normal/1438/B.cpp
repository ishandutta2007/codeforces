#include <cstdio>
#include <algorithm>

using namespace std;

const int N=1005;

int n;
int b[N];

bool solve()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (b[i]==b[j])
				return 1;
	return 0;
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
		printf(solve()?"YES\n":"NO\n");
	return 0;
}