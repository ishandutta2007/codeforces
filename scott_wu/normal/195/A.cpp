#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << ((a*c-1)/b + 1) - c << "\n";
	return 0;
}