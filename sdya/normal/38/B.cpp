#include <iostream>

using namespace std;

int x1, y1, x2, y2;

int main()
{
	char s1, s2;
	char s3, s4;
	scanf("%c%c\n%c%c", &s1, &s2, &s3, &s4);
	x1 = s1 - 'a' + 1; y1 = s2 - '0';
	x2 = s3 - 'a' + 1; y2 = s4 - '0';

	int res = 0;
	for (int i = 1; i <= 8; i ++)
		for (int j = 1; j <= 8; j ++)
			if (!(i == x1 && j == y1) && !(i == x2 && j == y2))
				if (x1 != i && y1 != j && abs((i - x2) * (j - y2)) != 2 && abs((i - x1) * (j - y1)) != 2) res ++;

	cout << res << endl;
	return 0;
}