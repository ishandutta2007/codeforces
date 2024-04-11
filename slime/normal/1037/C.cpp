#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1000005
#define ll long long
using namespace std;
char a[maxn], b[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	scanf("%s", a + 1);
	scanf("%s", b + 1);
	int ans = 0;
	for(int i = 1; i < n; i++)
		if(a[i] != b[i] && a[i + 1] != b[i + 1] && a[i] != a[i + 1])
			swap(a[i], a[i + 1]), ans++;
	for(int i = 1; i <= n; i++)
		if(a[i] != b[i])
			ans++;
	printf("%d\n", ans);
	return 0;
}