#include <bits/stdc++.h>
using namespace std;
int T , n , m;
long long L = 1;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%d" , &n , &m);
		if(n > m) printf("%d\n" , n + m);
		if(n == m) printf("%d\n" , n);
		if(n < m)
		{
			int x = n;
			n = (m / n) * n;
			if(m == n) n -= x;
			printf("%d\n" , (n + m) / 2);
		}
	}
	return 0;
}