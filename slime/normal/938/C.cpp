#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#define maxnod 1000005
#define maxn 40005
#define ll long long 
#define ld long double
using namespace std;
int sq[maxn];
int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 0; i < maxn; i++)
		sq[i] = i * i;
	for(int i = 0; i < t; i++)
	{
		int x;
		scanf("%d", &x);
		bool flag = 0;
		int n, m;
		for(int j = 0; j < maxn; j++)
		{
			if(sq[j] <= x) continue;
			int lst = sq[j] - x;
			int l = 0, r = maxn - 1;
			while(l < r)
			{
				int mid = (l + r) >> 1;
				if(sq[mid] >= lst) r = mid;
				else l = mid + 1;
			}
			if(sq[l] != lst) continue;
			n = j, m = n / l;
			if(n / m != l) continue;
			flag = 1;
			break;
		}
		if(flag) printf("%d %d\n", n, m);
		else printf("-1\n");
	}
	return 0;
 }