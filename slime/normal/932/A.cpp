#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 2005
using namespace std;
char inp[maxn], otp[maxn];
int main()
{
	scanf("%s", inp);
	int l = strlen(inp);
	for(int i = 0; i < l; i++)
		printf("%c", inp[i]);
	for(int i = l - 1; i >= 0; i--)
		printf("%c", inp[i]);
	printf("\n");
	return 0;
 }