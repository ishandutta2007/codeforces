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
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] >= 'A' && a[i] <= 'Z')
			a[i] += 'a' - 'A';
		if (b[i] >= 'A' && b[i] <= 'Z')
			b[i] += 'a' - 'A';
	}
	if (a == b)
		cout << "0\n";
	if (a < b)
		cout << "-1\n";
	if (a > b)
		cout << "1\n";
}