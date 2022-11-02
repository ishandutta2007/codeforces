#include <iostream>

using namespace std;

int n, x;
int d[2000];

int main()
{
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; i ++)
		scanf("%d", &d[i]);
	int res = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = i + 1; j <= n; j ++)
			if (abs(d[i] - d[j]) <= x) res ++;
	cout << res + res << endl;
	return 0;
}