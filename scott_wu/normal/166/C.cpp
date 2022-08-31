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
	int N, X;
	int num[510];
	
	cin >> N >> X;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	
	sort (num, num + N);
	
	int lo = N, hi = N;
	for (int i = 0; i < N; i++)
	{
		if (num[i] == X)
			hi = i;
		if (num[i] == X)
			lo = min (i, lo);
	}
	
	if (lo != N)
	{
		lo++; hi++;
		
		if (lo <= (N + 1) / 2 && (N + 1) / 2 <= hi)
		{
			cout << "0\n";
			return 0;
		}
		
		if (lo > (N + 1) / 2)
		{
			int nval = N;
			while (true)
			{
				N++;
				if (lo <= (N + 1) / 2)
					break;
			}
			cout << N - nval << "\n";
		}
		else
		{
			int nval = N;
			while (true)
			{
				N++;
				hi++;
				if ((N + 1) / 2 <= hi)
					break;
			}
			cout << N - nval << "\n";
		}
		return 0;
	}
	
	lo = -1;
	for (int i = 0; i < N; i++)
		if (num[i] < X)
			lo = i;
	
	N++;
	lo += 2; hi = lo;
	
	if (lo <= (N + 1) / 2 && (N + 1) / 2 <= hi)
	{
		cout << "1\n";
		return 0;
	}

	if (lo > (N + 1) / 2)
	{
		int nval = N;
		while (true)
		{
			N++;
			if (lo <= (N + 1) / 2)
				break;
		}
		cout << N - nval + 1 << "\n";
	}
	else
	{
		int nval = N;
		while (true)
		{
			N++;
			hi++;
			if ((N + 1) / 2 <= hi)
				break;
		}
		cout << N - nval + 1 << "\n";
	}
	return 0;
}