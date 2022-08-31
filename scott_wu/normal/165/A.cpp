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
	int N;
	int x[210], y[210];
	
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> x[i] >> y[i];
	
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		bool t[4] = {0, 0, 0, 0};
		
		for (int j = 0; j < N; j++)
		{
			if (x[i] == x[j])
			{
				if (y[i] < y[j])
					t[0] = true;
				if (y[i] > y[j])
					t[1] = true;
			}
			if (y[i] == y[j])
			{
				if (x[i] < x[j])
					t[2] = true;
				if (x[i] > x[j])
					t[3] = true;
			}
		}
		
		if (t[0] && t[1] && t[2] && t[3])
			ans++;
	}
	cout << ans << "\n";
}