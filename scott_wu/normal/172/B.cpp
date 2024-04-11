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
	int last[100100];
	for (int i = 0; i < 100100; i++)
		last[i] = -1;
	
	int a, b, m, r;
	int num = 0;
	cin >> a >> b >> m >> r;
	
	last[r] = 0;
	for (int i = 0; i < 200100; i++)
	{
		r = (a * r + b) % m;
		if (last[r] != -1)
		{
			cout << i + 1 - last[r] << "\n";
			return 0;
		}
		last[r] = i + 1;
	}
	return 0;
}