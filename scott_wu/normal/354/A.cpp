#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N;
ll L, R, QL, QR;

ll w[MAXN];

ll add (int left, int right)
{
	if (left == right) return 0;
	
	if (left > right)
		return QL * (left - right - 1);
	else
		return QR * (right - left - 1);
}

int main()
{
	cin >> N >> L >> R >> QL >> QR;
	
	ll lsum = 0, rsum = 0;
	
	for (int i = 0; i < N; i++)
	{
		cin >> w[i];
		rsum += w[i];
	}
	
	
	ll ans = 1e15;
	for (int i = 0; i <= N; i++)
	{
		ans = min (ans, lsum * L + rsum * R + add (i, N - i));
		
		lsum += w[i];
		rsum -= w[i];
	}
	
	cout << ans << "\n";
	return 0;
}