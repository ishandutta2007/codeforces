#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define mod 998244353
#define maxn 300005
#define ll long long
using namespace std;
int n, k;
char inp[maxn];
bool fl[maxn];
int st[maxn], top = 0;
int main()
{
	scanf("%d%d", &n, &k);
	scanf("%s", inp);
	for(int i = 0; i < n; i++)
		if(inp[i] == '(')
			st[top++] = i;
		else
		{
			if(k && top)
				fl[st[top - 1]] = 1, fl[i] = 1, top--, k -= 2;
		}
	for(int i = 0; i < n; i++)
		if(fl[i]) printf("%c", inp[i]);
	return 0;
}