#include <iostream>
#include <vector>

using namespace std;

int x1, y1, z1;
int x2, y2, z2;

int main()
{
	cin >> x1 >> y1 >> z1;
	cin >> x2 >> y2 >> z2;
	if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2) <= 2)
		printf("YES\n"); else
		printf("NO\n");
	return 0;
}