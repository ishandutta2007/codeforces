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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	
	if (d >= a - 1 && d <= 2 * a + 2)
		cout << "YES\n";
	else if (c >= b - 1 && c <= 2 * b + 2)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}