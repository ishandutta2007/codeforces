#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath> 
#include <algorithm>
#include <vector>
#define maxn 20005 // imp
#define maxk 305
#define ll long long
using namespace std;
struct th
{
	int a, b;
	bool operator < (const th &x)const
	{
		if(b != x.b) return b < x.b;
		return a < x.a; 
	}
}p[maxn];
bool can[2][maxn]; // 0can
int mns[maxn];
int mst[maxn];
int main()
{
	int n, l, r;
	scanf("%d%d%d", &n, &l, &r);
	for(int i = 1; i <= n; i++)
		scanf("%d", &p[i].a);
	for(int i = 1; i <= n; i++)
		scanf("%d", &p[i].b);
	sort(p + 1, p + n + 1);
	can[0][0] = can[1][0] = 1;
	int pl = 0;
	for(int i = 1; i <= n; i++)
	{
		if(p[i].b == 1)
		{
			pl = i;
			break;
		}
		for(int j = maxn - 1; j >= 0; j--)
			if(can[0][j]) can[0][j + p[i].a] = 1;
	}
	if(!pl)
	{
		printf("0\n");
		return 0;
	}
	mns[maxn - 1] = maxn;
	for(int j = maxn - 2; j >= 0; j--)
	{
		if(can[0][j]) mns[j] = j;
		else mns[j] = mns[j + 1];
	}
	int ans = 0;
	int sum1 = 0;
	for(int i = n; i >= pl - 1; i--)
	{	// pl ~ i  
		int sum = 0;
		for(int j = pl; j <= i; j++)
		{
			int nxt = sum + p[j].a;
			if(j == i) nxt = maxn;
			for(int k = sum; k < nxt; k++)
				mst[k] = j - pl + 1;
			sum += p[j].a;
		}
		if(i == pl - 1)
			for(int j = 0; j < maxn; j++)
				mst[j] = 0;
		for(int j = 0; j < maxn; j++)
		{
			if(!can[1][j]) continue;
			int lst = j;
			if(j < l) lst += mns[l - j];
			if(lst > r) continue;
			int nans = mst[r - lst];
			if(j != sum1 && r - lst >= sum) nans++;
			ans = max(ans, nans);
		}
		if(i == pl - 1) break;
		sum1 += p[i].a;
		for(int j = maxn - 1; j >= 0; j--)
			if(can[1][j]) can[1][j + p[i].a] = 1;
	}
	printf("%d\n", ans);
	return 0;
}