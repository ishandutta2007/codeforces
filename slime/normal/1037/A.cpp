#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100005
#define ll long long
using namespace std;
ll dp[3][maxn];
int tp[maxn];
int a[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	int ns = 1, cnt = 1;
	while(ns < n)
	{
		ns = ns * 2 + 1, cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}