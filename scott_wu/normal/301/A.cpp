#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int N;
int num[1100];

int main()
{
	cin >> N;
	for (int i = 0; i < 2 * N - 1; i++)
		cin >> num[i];
	
	if (N % 2)
	{
		int ans = 0;
		for (int i = 0; i < 2 * N - 1; i++)
			ans += abs (num[i]);
		cout << ans << "\n";
		return 0;
	}
	
	int acount = 0;
	for (int i = 0; i < 2 * N - 1; i++)
		if (num[i] < 0)
			acount++;
	
	if (acount % 2 == 0)
	{
		int ans = 0;
		for (int i = 0; i < 2 * N - 1; i++)
			ans += abs (num[i]);
		cout << ans << "\n";
		return 0;
	}
	else
	{
		int ans = 0;
		int lo = 1e9;
		for (int i = 0; i < 2 * N - 1; i++)
		{
			ans += abs (num[i]);
			lo = min (lo, abs (num[i]));
		}
		cout << ans - lo - lo << "\n";
		return 0;
	}
}