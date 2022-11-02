#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main() {
	string s;
	getline(cin, s);

	long long c = 0, z = s.length(), k = 0;
	for (long long i = z - 1; i >= 0; i--)
	{
		if (s[i] == 'a')
		{
			c += (z - i - 1 - k + c) % 1000000007;
			k++;
		}
	}

	cout << c % 1000000007;
	return 0;
}