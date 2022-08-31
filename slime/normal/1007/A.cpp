#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100005
using namespace std;
int a[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int pl = n;
	int ns = 0;
	for(int i = n; i >= 1; i--)
	{
		while(a[pl] >= a[i] && pl) pl--;
		if(pl == 0) break;
		ns++, pl--;
	}
	printf("%d\n", ns);
	return 0;
 }