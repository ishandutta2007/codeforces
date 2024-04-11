#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int a, b, r;
	cin >> a >> b >> r;
	if (r * 2 <= min (a, b))
		cout << "First\n";
	else
		cout << "Second\n";
	return 0;
}