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
	int num[1100];
	
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	
	int ans = 0;
	for (int i = 1; i < N; i++)
	{
		bool c1 = true, c2 = true;
		
		for (int j = i - 1; j >= 0; j--)
		{
			if (num[j] >= num[i])
				c1 = false;
			if (num[j] <= num[i])
				c2 = false;
		}
		
		if (c1 || c2)
			ans++;
	}
	
	cout << ans << "\n";
}