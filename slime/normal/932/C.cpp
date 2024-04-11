#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#define maxnod 1000005
#define maxn 4
#define ll long long 
#define ld long double
using namespace std;

int main()
{
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	bool flag = 0;
	for(int i = 0; i * a <= n; i++)
	{
		if((n - i * a) % b) continue;
		flag = 1;
		for(int j = 1; j <= i; j++)
		{
			for(int k = 1; k <= a; k++)
			{
				int ed = (j - 1) * a + k + 1;
				if(k == a) ed -= a;
				printf("%d ", ed);
			}
		}
		int npl = i * a + 1;
		while(npl <= n)
		{
			for(int j = npl; j <= npl + b - 1; j++)
			{
				int ed = j + 1;
				if(ed == npl + b) ed -= b;
				printf("%d ", ed);
			}
			npl += b;
		}
		break;
	}
	if(!flag) printf("-1\n");
	return 0;
 }