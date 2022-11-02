#include <iostream>
#include <algorithm>

using namespace std;

int a[5];

int main()
{
	for (int i = 1; i <= 4; i ++)
		scanf("%d", &a[i]);
	sort(a + 1, a + 5);
	bool t = false, s = false;
	for (int i = 1; i <= 4; i ++)
		for (int j = i + 1; j <= 4; j ++)
			for (int k = j + 1; k <= 4; k ++)
				if (a[k] < a[i] + a[j]) t = true; else
					if (a[k] == a[i] + a[j]) s = true;
	if (t)
		printf("TRIANGLE\n"); else
		if (s)
			printf("SEGMENT\n"); else
			printf("IMPOSSIBLE\n");
	return 0;
}