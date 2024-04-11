#include <iostream>
#include <vector>

using namespace std;

int a[200], n;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", &a[i]);

	vector < int > res;
	int t = 1;
	for (int i = 1; i <= n; i ++)
		if (a[i] == t) res.push_back(2000 + i), t ++;
	printf("%d\n", (int)(res.size()));
	for (int i = 0; i < res.size(); i ++)
		printf("%d ", res[i]);
	printf("\n");
	return 0;
}