#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <set>

using namespace std;
typedef long long ll;

int main()
{
	int N, arr[1100];
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	int a = 0, b = 0;
	
	int lo = 0, hi = N - 1;
	for (int i = 0; i < N; i++)
	{
		if (i % 2 == 0)
		{
			if (arr[lo] > arr[hi])
			{
				a += arr[lo];
				lo++;
			}
			else
			{
				a += arr[hi];
				hi--;
			}
		}
		else
		{
			if (arr[lo] > arr[hi])
			{
				b += arr[lo];
				lo++;
			}
			else
			{
				b += arr[hi];
				hi--;
			}
		}
	}
	cout << a << " " << b << "\n";
	return 0;
}