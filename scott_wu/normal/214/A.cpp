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
	int n, m;
	cin >> n >> m;
	
	int ans = 0;
	for (int i = 0; i <= 1000; i++)
		for (int j = 0; j <= 1000; j++)
			if (i * i + j == n && j * j + i == m)
				ans++;
	cout << ans << "\n";
}