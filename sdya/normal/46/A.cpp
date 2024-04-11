#include <iostream>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int c = 0;
	for (int i = 1; i < n; i ++)
		c += i, c %= n, printf("%d ", c + 1);
	printf("\n");
	return 0;
}