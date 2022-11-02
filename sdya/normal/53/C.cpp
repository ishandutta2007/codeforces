#include <iostream>

using namespace std;

int n;

int main()
{
	scanf("%d", &n);
	int l = 0, r = n + 1;
	int t = 0;
	while (t < 11000)
	{
		if (l + 1 < r) printf("%d ", l + 1), l ++;
		if (l < r - 1) printf("%d ", r - 1), r --;
		t ++;
	}
	printf("\n");
	return 0;
}