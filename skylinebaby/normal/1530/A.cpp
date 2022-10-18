#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);
		int x = 0;
		while(n)
		{
			x = max(x, n % 10);
			n /= 10;
		} 
		printf("%d\n", x);
	}
	return 0;
}