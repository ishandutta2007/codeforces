#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 100100;
const int MAXM = 55;
const int MAXP = (1 << 21) + 100;

int N, M, D;
int color[MAXN];
int last[MAXM];

bool good[MAXP]; // possible values of the converse

void flood (int x)
{
	if (!good[x]) return;
	good[x] = false;
	for (int i = 0; i < M; i++)
		if (!(x & (1 << i)))
			flood (x + (1 << i));
}

int main()
{
	cin >> N >> M >> D;
	for (int i = 0; i < M; i++)
	{
		int s; cin >> s;
		for (int j = 0; j < s; j++)
		{
			int t; cin >> t;
			color[t-1] = i;
		}
	}
	
	for (int i = 0; i < MAXM; i++)
		last[i] = -1e9;
	
	for (int i = 0; i < MAXP; i++)
		good[i] = true;
	
	for (int i = 0; i < N; i++)
	{
		last[color[i]] = i;
		
		if (i >= D - 1)
		{
			int tot = 0;
			for (int j = 0; j < M; j++)
				if (last[j] >= i - D + 1)
					tot += (1 << j);
			good[tot] = false;
		}
	}
	
	for (int i = 0; i < (1 << M); i++)
	{
		if (!good[i])
		{
			for (int j = 0; j < M; j++)
				if (!(i & (1 << j)))
					flood (i + (1 << j));
		}
	}
	
	int ans = MAXM;
	for (int i = 0; i < (1 << M); i++)
		if (good[i])
		{
			//cout << i << "\n";
			int cnt = 0;
			for (int j = 0; j < M; j++)
				if (!(i & (1 << j)))
					cnt++;
			ans = min (ans, cnt);
		}
	cout << ans << "\n";
	return 0;
}