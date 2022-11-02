#include <iostream>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

int n;
int a[1100][4];

int main()
{
	scanf("%d\n", &n);
	for (int i = 1; i <= n; i ++)
	{
		if (i != 1)
		{
			char s1, s2;
			scanf("%c%c\n", &s1, &s2);
		}
		char s;
		scanf("%c", &s);
		a[i][0] = s - '0';
		scanf("%c\n", &s);
		a[i][1] = s - '0';
		scanf("%c", &s);
		a[i][3] = s - '0';
		scanf("%c\n", &s);
		a[i][2] = s - '0';
	}

	int d = 0;
	for (int i = 1; i <= n; i ++)
	{
		bool good = true;
		for (int j = 1; j < i; j ++)
		{
			for (int k = 0; k < 4; k ++)
			{
				bool f = true;
				for (int l = 0; l < 4; l ++)
					if (a[j][l] != a[i][(k + l) % 4]) f = false;
				if (f) good = false;
			}
		}
		if (good) d ++;
	}

	cout << d << endl;
	return 0;
}