#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <stack>

using namespace std;

char s[210000];
char c[210000];
int k = 0;

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	gets(c);
	int n = strlen(c);
	for (int i = 0; i < n; i ++)
		if (k == 0 || s[k] != c[i]) k ++, s[k] = c[i]; else k --;
	for (int i = 1; i <= k; i ++)
		printf("%c", s[i]);
	printf("\n");

	return 0;
}