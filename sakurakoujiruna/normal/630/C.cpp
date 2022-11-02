#include <iostream>
using namespace std;

typedef long long intl;

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	cout << (1LL << (n + 1)) - 2 << '\n';
	return 0;
}