#include <iostream>

using namespace std;

int a[200];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i ++)
		scanf("%d", &a[i]);

	int best = 0;
	for (int i = 0; i < n; i ++)
		if (abs(a[i] - a[(i + 1) % n]) < abs(a[best] - a[(best + 1) % n]))
			best = i;
	printf("%d %d\n", (best % n) + 1, (best + 1) % n + 1);

	return 0;
}