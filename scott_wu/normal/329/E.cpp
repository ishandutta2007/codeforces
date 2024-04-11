#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
pair <int, int> city[MAXN];
int xval[MAXN], yval[MAXN];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> city[i].first >> city[i].second;
		
		xval[i] = city[i].first;
		yval[i] = city[i].second;
	}
	
	sort (xval, xval + N);
	sort (yval, yval + N);
	
	ll tot = 0;
	for (int i = 0; i < N; i++)
	{
		if (i * 2 < N - 1)
			tot -= xval[i] + yval[i];
		if (i * 2 > N - 1)
			tot += xval[i] + yval[i];
	}
	tot *= 2;
	
	if (N % 2 == 0)
	{
		bool bad1 = false, bad2 = false;
		for (int i = 0; i < N; i++)
		{
			if (city[i].first <= xval[N / 2 - 1] && city[i].second >= yval[N / 2])
				bad1 = true;
			if (city[i].first >= xval[N / 2] && city[i].second <= yval[N / 2 - 1])
				bad1 = true;
			
			if (city[i].first <= xval[N / 2 - 1] && city[i].second <= yval[N / 2 - 1])
				bad2 = true;
			if (city[i].first >= xval[N / 2] && city[i].second >= yval[N / 2])
				bad2 = true;
		}
		
		if (bad1 && bad2)
			tot -= 2 * min (xval[N / 2] - xval[N / 2 - 1], yval[N / 2] - yval[N / 2 - 1]);
		
		cout << tot << "\n";
	}
	else
	{
		bool good = false, bad1 = false, bad2 = false;
		for (int i = 0; i < N; i++)
		{
			if (city[i].first < xval[N / 2] && city[i].second > yval[N / 2])
				bad1 = true;
			if (city[i].first > xval[N / 2] && city[i].second < yval[N / 2])
				bad1 = true;
			
			if (city[i].first < xval[N / 2] && city[i].second < yval[N / 2])
				bad2 = true;
			if (city[i].first > xval[N / 2] && city[i].second > yval[N / 2])
				bad2 = true;
			
			if (city[i].first == xval[N/2] && city[i].second != yval[N/2])
				good = true;
			if (city[i].first != xval[N/2] && city[i].second == yval[N/2])
				good = true;
		}
		
		if (!good && bad1 && bad2)
			tot -= 2 * min (min (xval[N / 2] - xval[N / 2 - 1], xval[N / 2 + 1] - xval[N / 2]),
							min (yval[N / 2] - yval[N / 2 - 1], yval[N / 2 + 1] - yval[N / 2]));
		
		cout << tot << "\n";
	}
	return 0;
}