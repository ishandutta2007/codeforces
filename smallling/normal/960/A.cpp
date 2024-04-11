#include <bits/stdc++.h>

using namespace std;

char s[1000010];

int main()
{
	scanf("%s", s + 1);
	int n = strlen(s + 1), i = 1;
	while(i <= n)
	{
		if(s[i] != 'a')break;
		i++;
	}
	if(i == 1)
	{
		puts("NO");
		return 0;
	}
	int j = i;
	while(j <= n)
	{
		if(s[j] != 'b')break;
		j++;
	}
	if(j == i)
	{
		puts("NO");
		return 0;
	}
	int k = j;
	while(k <= n)
	{
		if(s[k] != 'c')break;
		k++;
	}
	if(k <= n)
	{
		puts("NO");
		return 0;
	}
	if(k - j != j - i && k - j != i - 1)puts("NO");
	else puts("YES");
}