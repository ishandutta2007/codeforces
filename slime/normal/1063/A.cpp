#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100005
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
char s[maxn];
int cnt[27];
int main()
{
	int n;
	scanf("%d", &n);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i++)
		cnt[s[i] - 'a']++;
	for(int i = 0; i < 26; i++)
		for(int j = 0; j < cnt[i]; j++)
			printf("%c", char(i + 'a'));
	return 0;
 }