#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#define maxn 200005
#define ll long long
#define mod 998244353
using namespace std;
int a[maxn];
int n;
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		a[i] = i;
	int mns = maxn * 2, mpl = 0;
	for(int i = 1; i <= n; i++) 
	{
		int nans = i + n / i;
		if(n % i) nans++;
		if(nans < mns)
			mpl = i, mns = nans;
	}
	for(int i = 1; i <= n; i += mpl)
	{
		int ls = i, rs = min(n, i + mpl - 1);
		for(int j = ls; rs + ls - j > j; j++)
			swap(a[j], a[rs + ls - j]);
	}
	for(int i = 1; i <= n; i++)
		printf("%d ", a[i]);
		
	return 0;
}