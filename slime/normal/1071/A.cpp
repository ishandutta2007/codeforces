#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 200005
#define ll long long

using namespace std;
int a, b;
int ns[maxn][2], cnt[2];
int main()
{
	scanf("%d%d", &a, &b);
	for(ll i = 1; i <= maxn; i++)
	{
		if(i * (i + 1) / 2 > (a + b)) 
		{
			i--;
			for(int j = i; j >= 1; j--)
				if(a >= j)
					a -= j, ns[cnt[0]++][0] = j;
				else 
					ns[cnt[1]++][1] = j;
			for(int k = 0; k < 2; k++)
			{
				printf("%d\n", cnt[k]);
				for(int l = 0; l < cnt[k]; l++)
					printf("%d ", ns[l][k]);
				printf("\n");
			}
			break;
		}
	}
	return 0;
}