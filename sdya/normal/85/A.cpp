#include <iostream>
#include <string.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>

using namespace std;

int n;
char a[10][110];

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d", &n);
	if (n == 1)
	{
		cout << 'a' << endl;
		cout << 'a' << endl;
		cout << 'b' << endl;
		cout << 'b' << endl;
		return 0;
	}
	if (n % 2 == 0)
	{
		int x = 0;
		for (int i = 1; i <= n; i += 2, x = 1 - x)
			a[1][i] = 'a' + x, a[1][i + 1] = 'a' + x;
		for (int i = 2; i <= n; i += 2, x = 1 - x)
			a[2][i] = 'c' + x, a[2][i + 1] = 'c' + x;
		for (int i = 2; i <= n; i += 2, x = 1 - x)
			a[3][i] = 'e' + x, a[3][i + 1] = 'e' + x;
		for (int i = 1; i <= n; i += 2, x = 1 - x)
			a[4][i] = 'g' + x, a[4][i + 1] = 'g' + x;
		a[2][1] = a[3][1] = 'i';
		a[2][n] = a[3][n] = 'j';
	} else
	{
		int x = 0;
		for (int i = 1; i <= n; i += 2, x = 1 - x)
			a[1][i] = 'a' + x, a[1][i + 1] = 'a' + x;
		for (int i = 1; i <= n; i += 2, x = 1 - x)
			a[2][i] = 'c' + x, a[2][i + 1] = 'c' + x;
		for (int i = 2; i <= n; i += 2, x = 1 - x)
			a[3][i] = 'e' + x, a[3][i + 1] = 'e' + x;
		for (int i = 2; i <= n; i += 2, x = 1 - x)
			a[4][i] = 'g' + x, a[4][i + 1] = 'g' + x;
		a[1][n] = a[2][n] = 'i';
		a[3][1] = a[4][1] = 'j';
	}
	for (int i = 1; i <= 4; i ++)
	{
		for (int j = 1; j <= n; j ++)
			cout << a[i][j];
		cout << endl;
	}

	return 0;
}