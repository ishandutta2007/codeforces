#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100005
#define ll long long
using namespace std;
int n;
int b[maxn];
struct th
{
	int x, id;
	bool operator < (const th &t)const
	{
		return x < t.x;
	}
}a[maxn];
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i].x), 
		a[i].x = n - a[i].x, 
		a[i].id = i;
	sort(a, a + n);
	int cnt = 1;
	for(int i = 0; i < n; )
	{
		int j = i;
		while(j < n && a[j].x == a[i].x) j++;
		if((j - i) % a[i].x)
		{
			printf("Impossible\n");
			return 0;
		}
		for(int k = i; k < j; k += a[i].x)
		{
			for(int l = k; l < k + a[i].x; l++)
				b[a[l].id] = cnt;
			cnt++;
		}
		i = j;
	}
	printf("Possible\n");
	for(int i = 0; i < n; i++)
		printf("%d ", b[i]);
	return 0;
}