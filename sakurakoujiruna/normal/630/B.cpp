#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	double a, b;
	cin >> a >> b;
	cout << setprecision(12) << a * pow(1.000000011, b) << '\n';
}