#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long

#define maxn 400005
using namespace std;
int fa[maxn]; 
char inp[2][maxn];
char otp[2][maxn];
int gfa(int a)
{
	if(fa[a] == a) return a;
	return fa[a] = gfa(fa[a]);
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < 27; i++)
		fa[i] = i;
	scanf("%s", inp[0]);
	scanf("%s", inp[1]);
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		if(gfa(inp[0][i] - 'a') != gfa(inp[1][i] - 'a'))
			otp[0][cnt]	= inp[0][i], otp[1][cnt++] = inp[1][i];
		fa[gfa(inp[0][i] - 'a')] = gfa(inp[1][i] - 'a');
	}	
	printf("%d\n", cnt);
	for(int i = 0; i < cnt; i++)
		printf("%c %c\n", otp[0][i], otp[1][i]);
	return 0;
}
/*
2
1 1 1
2 2 1
*/