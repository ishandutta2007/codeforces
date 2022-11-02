#include <iostream>
#include <set>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

long long d[60][10];
int a[60], n;
string s;

bool check(int a, int b, int c)
{
	if ((a + b) % 2 == 0) return c == ((a + b) / 2);
	if (c == ((a + b) / 2)) return true;
	if ((c - 1) == ((a + b) / 2)) return true;
	return false;
}

int main()
{
	cin >> s;
	n = s.size();
	for (int i = 1; i <= n; i ++)
		a[i] = s[i - 1] - '0';
	for (int i = 0; i < 10; i ++)
		d[1][i] = 1LL;
	for (int i = 2; i <= n; i ++)
		for (int j = 0; j < 10; j ++)
			for (int k = 0; k < 10; k ++)
				if (check(a[i], k, j))
					d[i][j] += d[i - 1][k];

	long long res = 0;
	for (int i = 0; i < 10; i ++)
		res += d[n][i];
	long long add = 1;
	for (int i = 2; i <= n; i ++)
		if (!check(a[i], a[i - 1], a[i])) {add = 0; break;}
	res -= add;
	cout << res << endl;
	return 0;
}