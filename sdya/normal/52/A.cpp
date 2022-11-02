#include <iostream>

using namespace std;

int n;
int a[4];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		int x;
		scanf("%d", &x);
		a[x] ++;
	}
	printf("%d\n", n - max(a[1], max(a[2], a[3])));
	return 0;
}