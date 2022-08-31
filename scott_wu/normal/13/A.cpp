#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int solve (int left, int tot)
{
	int x = 0;
	while (tot)
	{
		x += tot % left;
		tot /= left;
	}
	return x;
}

int gcf (int a, int b)
{
	return ((b == 0) ? a : gcf (b, a % b));
}

int main()
{
	int num, den;
	int x; cin >> x;
	
	num = 0;
	for (int i = 2; i <= x - 1; i++)
	{
		num += solve (i, x);
	}
	
	den = x - 2;
	int g = gcf (num, den);
	cout << num / g << "/" << den / g << "\n";
	return 0;
}