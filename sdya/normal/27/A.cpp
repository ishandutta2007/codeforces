#include <iostream>

using namespace std;

int a[5000];
int n;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	for (int i = 1; i <= 3001; i ++)
	{
		int good = true;
		for (int j = 1; j <= n; j ++)
			if (a[j] == i) good = false;
		if (good)
		{
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}