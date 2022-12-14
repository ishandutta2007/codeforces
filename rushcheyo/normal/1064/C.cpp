#include <bits/stdc++.h>
using namespace std;

int n;
char s[100005];

int main()
{
	scanf("%d%s", &n, s + 1);
	sort(s + 1, s + 1 + n);
	puts(s + 1);
	return 0;
}