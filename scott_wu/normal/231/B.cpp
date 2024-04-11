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
	int N, D, L;
	cin >> N >> D >> L;
	
	int lo = 0, hi = 0;
	for (int i = 0; i < N; i++)
	{
		if (i % 2 == 0)
		{
			hi += L;
			lo += 1;
		}
		else
		{
			hi -= 1;
			lo -= L;
		}
	}
	
	if (lo <= D && D <= hi)
	{
		int arr[110];
		for (int i = 0; i < N; i++)
		{
			if (i % 2 == 0)
				arr[i] = 1;
			else
				arr[i] = L;
		}
		
		int diff = D - lo;
		for (int i = 0; i < N; i++)
		{
			if (i % 2)
			{
				while (arr[i] > 1 && diff)
				{
					diff--;
					arr[i]--;
				}
			}
			else
			{
				while (arr[i] < L && diff)
				{
					diff--;
					arr[i]++;
				}
			}
		}
		
		for (int i = 0; i < N; i++)
			cout << arr[i] << " ";
		cout << "\n";
		
		return 0;
	}
	cout << "-1\n";
	return 0;
}