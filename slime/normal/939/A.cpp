#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 5005
using namespace std;
int f[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &f[i]);
	int flag = 0;
	for(int i = 1; i <= n; i++) 
		if(f[f[f[i]]] == i) flag = 1;
	if(flag) printf("YES\n");
	else printf("NO\n");
	return 0;
 }