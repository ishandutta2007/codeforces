#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1000005
#define ll long long 
using namespace std;
int f[maxn];
int cnt[10][maxn];
int main()
{
	for(int i = 1; i < maxn; i++)
	{
		if(i <= 9) f[i] = i;
		else
		{
			int ns = i;
			int nans = 1;
			while(ns)
			{
				if(ns % 10)
					nans *= ns % 10;
				ns /= 10;
			}
			f[i] = f[nans];
		}
	//	if(f[i] > 10) cout<<"???"<<endl;
		for(int j = 1; j <= 9; j++)
			cnt[j][i] = cnt[j][i - 1];
		cnt[f[i]][i]++;
	}
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++)
	{
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		int nans = cnt[k][r] - cnt[k][l - 1];
		printf("%d\n", nans);
	}
	return 0;
 }