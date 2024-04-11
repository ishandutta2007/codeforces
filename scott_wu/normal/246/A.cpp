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
	{
		cout << "-1\n";
		return 0;
	}
	
	for (int i = N; i >= 1; i--)
		cout << i << " ";
	cout << "\n";
	return 0;
}