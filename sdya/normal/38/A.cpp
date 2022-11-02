#include <iostream>

using namespace std;

int a[200];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= n; i ++)
		scanf("%d", &a[i]);
	int p, q;
	scanf("%d%d", &p, &q);
	int res = 0;
	for (int i = p + 1; i <= q; i ++)
		res += a[i];
	cout << res << endl;
	return 0;
}