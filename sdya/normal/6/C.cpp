#include <iostream>

using namespace std;

int n;
int a[110000];

int main()
{
	scanf("%d", &n);
	int s = 0;
	for (int i = 1; i <= n; i ++)
		scanf("%d", &a[i]), s += a[i];
	int x = 0;
	for (int i = 1; i <= n; x += a[i], i ++)
		if (x >= s - x - a[i])
		{
			if (x > s - x - a[i])
				printf("%d %d\n", i - 1, n - i + 1); else
				printf("%d %d\n", i, n - i);
			return 0;
		}
	return 0;
}