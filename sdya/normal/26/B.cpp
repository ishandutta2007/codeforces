#include <iostream>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

char s[1100000];
int n;

int main()
{
	gets(s);
	n = strlen(s);
	int res = 0, balanse = 0;
	for (int i = 0; i < n; i ++)
		if (s[i] == '(') balanse ++, res ++; else
			if (balanse > 0) balanse --, res ++;
	res -= balanse;
	cout << res << endl;
	return 0;
}