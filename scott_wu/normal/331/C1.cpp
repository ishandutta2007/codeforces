#include <iostream>
#include <cstdio>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;

int N;
int dp[MAXN];

void solve (int x)
{
	dp[x] = 1e9;
	int temp = x;
	
	while (temp)
	{
		dp[x] = min (dp[x], 1 + dp[x - (temp % 10)]);
		temp /= 10;
	}
}

int main()
{
	dp[0] = 0;
	cin >> N;
	
	for (int i = 1; i <= N; i++)
		solve (i);
	
	cout << dp[N] << "\n";
	return 0;
}