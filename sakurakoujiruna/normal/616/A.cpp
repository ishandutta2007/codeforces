#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

const int N = 1000011;

char a[N];
char b[N];

char check(char* a, char* b, int n)
{
	for(int i = 0; i < n; i ++)
		if(a[i] < b[i])
			return '<';
		else if(a[i] > b[i])
			return '>';
	return '=';
}

int main()
{
	//ios :: sync_with_stdio(false);
	scanf("%s", a);
	scanf("%s", b);
	int n = (int)strlen(a);
	int m = (int)strlen(b);

	if(n < m)
	{
		memmove(a + m - n, a, n);
		memset(a, '0', m - n);
	}
	else
	{
		memmove(b + n - m, b, m);
		memset(b, '0', n - m);
	}

	cout << check(a, b, max(n, m)) << '\n';
	return 0;
}