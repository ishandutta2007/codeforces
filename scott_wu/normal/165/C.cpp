#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

ll nsum[2000100];

int main()
{
	int k; string str;
	cin >> k >> str;
	
	for (int i = 0; i < 2000100; i++)
		nsum[i] = 0;
	
	int sum = 0;
	nsum[0] = 1;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '1')
			sum++;
		nsum[sum]++;
	}
	
	ll ans = 0;
	for (int i = 0; i <= sum; i++)
	{
		if (k == 0)
			ans += (nsum[i] * (nsum[i] - 1)) / 2;
		else
		ans += nsum[i] * nsum[k+i];}
	cout << ans << "\n";
	return 0;
}