#include <iostream>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

char s1[500], s2[500];
int a[5000], b[5000];

int main()
{
	gets(s1);
	gets(s2);
	for (int i = 0; i < strlen(s1); i ++)
		if (s1[i] != ' ') a[s1[i] + 1000] ++;
	for (int i = 0; i < strlen(s2); i ++)
		if (s2[i] != ' ') b[s2[i] + 1000] ++;
	for (int i = 0; i < 5000; i ++)
		if (a[i] < b[i])
		{
			printf("NO\n");
			return 0;
		}
	printf("YES\n");
	return 0;
}