#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
typedef long long ll;

int main()
{
	int N;
	int val[7];
	
	cin >> N;
	for (int i = 0; i < 7; i++)
		cin >> val[i];
	
	int cur = 0;
	while (true)
	{
		N -= val[cur];
		
		if (N <= 0)
		{
			cout << cur + 1 << "\n";
			break;
		}
		
		cur = (cur + 1) % 7;
	}
	
	return 0;
}