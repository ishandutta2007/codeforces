#include <iostream>
using namespace std;

int main()
{
	int kase;
	cin >> kase;
	while(kase --)
	{
		int a;
		cin >> a;
		cout << (360 % (180 - a) == 0 ? "YES" : "NO") << '\n';
	}
	return 0;
}