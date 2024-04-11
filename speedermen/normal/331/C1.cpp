#include <iostream>
#include <cstdio>
#include <memory.h>
#include <cstdlib>

using namespace std;

int d[1111111];
char buf[124];

int f(int x)
{
	if(x == 0)
		return 0;
	if(d[x] != -1)
		return d[x];
	string s = itoa(x, buf, 10);
	for(int i = 0; i < s.length(); ++i)
		if(s[i] != '0')
			if(d[x] == -1)
				d[x] = f(x - (s[i] - '0')) + 1;
			else
				d[x] = min(d[x], f(x - (s[i] - '0')) + 1);
	return d[x];
}

int main()
{
	int n;
	cin >> n;
	memset(d, -1, sizeof(d)); d[0] = 0;
	cout << f(n) << endl;
}