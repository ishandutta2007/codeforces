#include <iostream>
#include <string.h>
#include <cstring>
#include <string>

using namespace std;

int n, m;
int a[2000];
string s;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> n;
	cin >> s;
	for (int i = 0; i < s.size(); i ++)
		if (s[i] == '1') m ++, a[m] = i;
	for (int i = 3; i <= m; i ++)
		if (a[i] - a[i - 1] != a[2] - a[1]) {printf("NO\n"); return 0;}

	printf("YES\n");
	return 0;
}