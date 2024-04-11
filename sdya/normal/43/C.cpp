#include <iostream>

using namespace std;

int n;
int b[3];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		int x;
		scanf("%d", &x);
		int s = 0;
		while (x > 0)
			s += x % 10, x /= 10;
		b[s % 3] ++;
	}
	printf("%d\n", min(b[1], b[2]) + (b[0] / 2));
	return 0;
}