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
	int num[4];
	for (int i = 0; i < 4; i++)
		cin >> num[i];
	sort (num, num + 4);
	
	int ans = 0;
	for (int i = 0; i < 3; i++)
		if (num[i] == num[i+1])
			ans++;
	cout << ans << "\n";
}