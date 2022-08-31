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
	int N, K, T;
	cin >> N >> K >> T;
	int tot = (N * K * T) / 100;
	
	for (int i = 0; i < N; i++)
	{
		if (tot > K)
		{
			cout << K;
			tot -= K;
		}
		else
		{
			cout << tot;
			tot = 0;
		}
		if (i < N - 1) cout << " ";
	}
	cout << "\n";
	}