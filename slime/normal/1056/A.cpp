#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 105
#define ll long long

using namespace std;
int fl[maxn];
int nfl[maxn];
int main()
{
	for(int i = 0; i < maxn; i++) fl[i] = 1;
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		memset(nfl, 0, sizeof(nfl));
		for(int j = 0; j < k; j++)
		{
			int s;
			scanf("%d", &s);
			nfl[s] = 1;
		}
		for(int i = 0; i < maxn; i++)
			fl[i] = fl[i] & nfl[i];
	}
	for(int i = 0; i < maxn; i++)
		if(fl[i]) printf("%d ", i);
	return 0;
}