#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;
const int MAXD = 10100;
const int MAXN = 1100;
const ll MOD = 1e9 + 7;

int N;
int arr[MAXN];
ll poss[2 * MAXD];
ll prev[2 * MAXD];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	for (int i = 0; i < 2 * MAXD; i++)
		poss[i] = prev[i] = 0;
	
	prev[MAXD] = 1;
	
	ll ans = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 2 * MAXD; j++)
		{
			poss[j] = 0;
			if (j + arr[i] < 2 * MAXD)
				poss[j] += prev[j + arr[i]];
			if (j - arr[i] >= 0)
				poss[j] += prev[j - arr[i]];
		}
		for (int j = 0; j < 2 * MAXD; j++)
			prev[j] = poss[j] % MOD;
		
		ans = (ans + prev[MAXD]) % MOD;
		prev[MAXD] = (prev[MAXD] + 1) % MOD;
	}
	
	cout << ans << "\n";
	return 0;
}