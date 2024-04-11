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
	int N;
	cin >> N;
	int num[110];
	for (int i = 1; i <= N; i++)
		cin >> num[i];
	
	if (N == 1 || (N % 2) == 0)
	{
		cout << "-1\n";
		return 0;
	}
	
	int ans = 0;
	
	for (int i = (N - 1) / 2; i >= 2; i--)
	{
		int res = max (num[2*i], num[2*i+1]);
		ans += res;
		num[2*i] -= res;
		num[2*i+1] -= res;
		num[i] -= res;
		if (num[i] < 0)
			num[i] = 0;
		if (num[2*i] < 0)
			num[2*i] = 0;
		if (num[2*i+1] < 0)
			num[2*i+1] = 0;
	}
	ans += max (num[1], max (num[2], num[3]));
	cout << ans << "\n";
	return 0;
}