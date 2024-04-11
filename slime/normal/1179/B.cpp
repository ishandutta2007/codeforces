#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <deque>
#define maxn 300005
#define ll long long
#define maxn 200005
#define ll long long
using namespace std;
int n, m;
int main()
{
	cin>>n>>m;
	for(int i = 1; i <= n / 2; i++)
		for(int j = 1; j <= m; j++)
			printf("%d %d\n", i, j), 
			printf("%d %d\n", n + 1 - i, m + 1 - j);
	if(n & 1)
	{
		int md = (n + 1) / 2;
		for(int j = 1; j <= m / 2; j++)
			printf("%d %d\n", md, j), 
			printf("%d %d\n", md, m + 1 - j);
		if(m & 1)
			printf("%d %d\n", md, (m + 1) / 2);
	}
	return 0;
}