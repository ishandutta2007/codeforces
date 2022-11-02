#include <iostream>

using namespace std;

int a[200];
int n;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			for (int k = 1; k <= n; k ++)
				if (i != j && i != k && j != k && a[i] == a[j] + a[k])
				{
					printf("%d %d %d\n", i, j, k);
					return 0;
				}
	cout << "-1" << endl;
	return 0;
}