#include <iostream>

using namespace std;

int n;
int a[200];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i ++)
	{
		bool good = false;
		for (int j = 1; j <= n; j ++)
			if (i != j && (a[i] + a[j]) % 2 == 0) good = true;
		if (!good)
		{
			printf("%d\n", i);
			return 0;
		}
	}

	return 0;
}