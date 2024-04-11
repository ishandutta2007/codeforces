#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		int res = 0;
		for (int j = 0; j < N; j++)
		{
			int num;
			cin >> num;
			if (j != i)
				res |= num;
		}
		cout << res;
		if (i < N - 1)
			cout << " ";
	}
	cout << "\n";
	return 0;
}