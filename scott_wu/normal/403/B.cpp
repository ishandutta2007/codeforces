#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;
const int MAXN = 5100;

int N, M;
vector <int> plist;
int b[MAXN];
int arr[MAXN];
int glist[MAXN];
int dp[MAXN];
int pscore[MAXN];

inline bool prime (int x)
{
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}

int score (int x)
{
	int res = 0;
	for (int i = 0; i < M; i++)
		while (x % b[i] == 0)
		{
			x /= b[i];
			res--;
		}
	
	for (int i = 0; i < plist.size(); i++)
		while (x % plist[i] == 0)
		{
			x /= plist[i];
			res++;
		}
	if (x > 1) res++;
	return res;
}

int gcf (int a, int b)
{
	return ((b == 0) ? a : (gcf (b, a % b)));
}

int main()
{
	plist.clear();
	for (int i = 2; i < 33000; i++)
		if (prime (i))
			plist.push_back (i);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < M; i++)
		cin >> b[i];
	
	glist[0] = arr[0];
	for (int i = 1; i < N; i++)
		glist[i] = gcf (glist[i-1], arr[i]);
	for (int i = 0; i < N; i++)
		pscore[i] = score (glist[i]);
	pscore[N] = 0;
	
	for (int i = 0; i < N; i++)
		dp[i] = -1e9;
	dp[N] = 0;
	
	for (int i = N; i >= 0; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			dp[j] = max (dp[j], dp[i] + (pscore[i] - pscore[j]) * (j + 1));
		}
	}
	
	int tot = 0;
	for (int i = 0; i < N; i++)
		tot += score (arr[i]);
	int hi = 0;
	for (int i = 0; i < N; i++)
		hi = max (hi, dp[i]);
	
	//cout << tot << " " << hi << "\n";
	
	
	cout << tot + hi << "\n";
	return 0;
}