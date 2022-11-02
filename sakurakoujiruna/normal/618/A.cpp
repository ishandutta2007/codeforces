#include <iostream>
using namespace std;

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 25; i >= 0; i --)
		if((n >> i) & 1)
			cout << i + 1 << ' ';
	cout << '\n';

	return 0;
}