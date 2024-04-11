#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100005
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
int n, m;
char inp[maxn];
int main()
{
	cin>>n>>m;
	int l[2] = {maxn, maxn}, u[2] = {0, 0};
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", inp + 1);
		for(int j = 1; j <= m; j++)
			if(inp[j] == 'B')
				l[0] = min(l[0], i), 
				u[0] = max(u[0], i), 
				l[1] = min(l[1], j), 
				u[1] = max(u[1], j);
	}
	printf("%d %d\n", (u[0] + l[0]) / 2, (u[1] + l[1]) / 2);
	return 0;
}