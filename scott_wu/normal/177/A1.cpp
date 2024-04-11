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
	int arr[103][103];
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (i == j || i == n / 2 || j == n / 2 || i + j == n-1)
				sum += arr[i][j];
		}
	cout << sum << "\n";
	return 0;
}