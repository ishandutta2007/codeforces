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
	int N, ncount = 0;
	int arr[110];
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (arr[i] < 0)
			ncount++;
	}
	
	int res = max (1, (ncount + 1) / 2);
	cout << res << "\n";
	
	int cres = 0, cc = 0, last = -1;
	for (int i = 0; i < N; i++)
	{
		if (cres == res - 1)
		{
			cout << N - i;
			break;
		}
		if (arr[i] < 0)
		{
			cc++;
			if (cc == 2)
			{
				cout << i - last << " ";
				last = i;
				cres++;
				cc = 0;
			}
		}
	}
	return 0;
}