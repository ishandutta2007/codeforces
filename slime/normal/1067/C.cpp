#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define mod 998244353
#define maxn 500005
#define ll long long
using namespace std;
int main()
{
	int st[2] = {1, 2};
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		if(i % 3)
			printf("4 %d\n", st[0]), st[0]++;
		else
			printf("1 %d\n", st[1]), st[1] += 2;
	}
	return 0;
}