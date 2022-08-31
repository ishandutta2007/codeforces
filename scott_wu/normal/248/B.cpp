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
	int N;
	cin >> N;
	
	if (N <= 2)
		cout << "-1\n";
	else if (N == 3)
		cout << "210\n";
	else
	{
		int m = 1;
		for (int i = 0; i < N - 2; i++)
			m = (10 * m) % 21;
		
		m = (21 - m) % 21;
		
		cout << 1;
		for (int i = 0; i < N - 4; i++)
			cout << 0;
		cout << m / 10 << m % 10;
		cout << "0\n";
	}
	return 0;
}