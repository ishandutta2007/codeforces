#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, a, b, m = 1;
	scanf("%d %d %d", &n, &a, &b);
	while(a/m + b/m >= n)
	{
		m++;
	}
	if(m - 1 > min(a, b)) m = min(a, b) + 1;
	printf("%d", m - 1);
}