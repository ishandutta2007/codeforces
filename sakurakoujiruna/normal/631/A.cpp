#include <iostream>
using namespace std;

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	
	int a = 0, b = 0;
	for(int i = 0; i < n; i ++)
	{
		int x;
		cin >> x;
		a |= x;
	}
	for(int i = 0; i < n; i ++)
	{
		int x;
		cin >> x;
		b |= x;
	}
	cout << a + b << '\n';
	return 0;
}