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
	int n, a, b;
	cin >> n >> a >> b;
	cout << min (b + 1, n - a) << "\n";
	return 0;
}