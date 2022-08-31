#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1000005
using namespace std;
int nx[maxn], bpr[maxn];
int main()
{
	for(int i = 0; i < maxn; i++)
		nx[i] = i, bpr[i] = 1;
	for(int i = 2; i < maxn; i++)
	{
		if(!bpr[i]) continue;
		for(int j = 1; j * i < maxn; j++)
			nx[i * j] = min(nx[i * j], max(i + 1, (j - 1) * i + 1)), 
			bpr[i * j] = 0;
	}
	int x;
	scanf("%d", &x);
//	cout<<nx[14]<<endl;
	int nans = x;
	for(int i = nx[x]; i <= x; i++)
		nans = min(nans, nx[i]);
	printf("%d\n", nans);
	return 0;
}