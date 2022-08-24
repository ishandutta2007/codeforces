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
	int num[110];
	int n; cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> num[i];
	sort (num, num + n);
	
	bool check = true;
	for (int i = 1; i < n; i++)
		if (num[i] != num[0])
		{
			cout << num[i];
			return 0;
		}
	cout << "NO\n";
	return 0;
}