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
	int k;
	int num[12];
	
	cin >> k;
	for (int i = 0; i < 12; i++)
		cin >> num[i];
	sort (num, num + 12);
	
	int sum = 0;
	if (!k) {cout << "0\n"; return 0;}
	for (int i = 11; i >= 0; i--)
	{
		sum += num[i];
		if (sum >= k)
		{
			cout << 12 - i << "\n";
			return 0;
		}
	}
	cout << "-1\n";
}