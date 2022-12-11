#include <iostream>
#include <cstdio>
#include <cstdlib>

#define FOR(a, b) for (int a = 0; (a) < (b); ++a)

using namespace std;


int main()
{
	int n;
	cin >> n;
	int a = 0;
	FOR(i, n)
	{
		char c;
		cin >> c;
		if ((i + c - '0') % 2 == 0) a++;
	}
	cout << min(a, n - a);
	return 0;
}