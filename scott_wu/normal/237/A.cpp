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
	int N; cin >> N;
	int ans = 1;
	int count = 1;
	
	int h[100100], m[100100];
	for (int i = 0; i < N; i++)
	{
		cin >> h[i] >> m[i];
		
		if (i > 0)
		{
			if (h[i] == h[i-1] && m[i] == m[i-1])
				count++;
			else
				count = 1;
			ans = max (ans, count);
		}
	}
	cout << ans << "\n";
}