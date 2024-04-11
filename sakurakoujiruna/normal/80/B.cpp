#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int h, m;
	char c;
	cin >> h >> c >> m;
	if(h >= 12)
		h -= 12;
	cout << setprecision(12) << h * 30 + m * 0.5 << ' ';
	cout << setprecision(12) << m * 6 << '\n';
	return 0;
}