#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

bool lucky (int x)
{
	while (x)
	{
		if (!(x % 10 == 4 || x % 10 == 7))
			return false;
		x /= 10;
	}
	return true;
}

int main()
{
	int N; cin >> N;
	for (int i = 1; i <= N; i++)
		if (lucky(i) && N % i == 0)
		{
			cout << "YES\n";
			return 0;
		}
	cout << "NO\n";
	return 0;
}