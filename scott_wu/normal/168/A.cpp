#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
	int n, x, y;
	cin >> n >> x >> y;
	int sx = x;
	
	while (x * 100 < y * n)
	{
		x++;
	}
	
	cout << x - sx << "\n";
	return 0;
}