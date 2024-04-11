#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

bool pr[3100];

bool isp (int x)
{
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0) return false;
	return true;
}

int main()
{
	for (int i = 2; i < 3100; i++)
		pr[i] = isp (i);
	
	
	int n;
	cin >> n;
	int ans = 0;
	
	for (int i = 2; i <= n; i++)
	{
		int cnt = 0;
		for (int j = 2; j < 3000; j++)
			if (pr[j] && i % j == 0)
				cnt++;
		if (cnt == 2)
			ans++;
	}
	cout << ans << "\n";
	}