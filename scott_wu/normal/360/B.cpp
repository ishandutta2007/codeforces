#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;
const int MAXN = 2100;

int N, K;
int dp[MAXN]; // # [i] was the last taken
int arr[MAXN];

bool works (ll x)
{
	for (int i = 0; i < N; i++)
		dp[i] = i;
	for (int i = 1; i < N; i++)
		for (int j = 0; j < i; j++)
			if (abs (arr[j] - arr[i]) <= x * (i - j))
				dp[i] = min (dp[i], dp[j] + i - j - 1);
	
	for (int i = 0; i < N; i++)
		if (dp[i] + (N - 1 - i) <= K)
			return true;
	return false;
}

int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	ll lo = 0, hi = 1e10;
	
	while (lo < hi)
	{
		ll mid = (lo + hi) / 2;
		if (works (mid))
			hi = mid;
		else
			lo = mid + 1;
	}
	
	cout << lo << "\n";
	return 0;
}