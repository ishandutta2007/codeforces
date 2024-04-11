#include <iostream>
#include <vector>
#include <map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

long long a, b, n;

map < pair < long long, long long > , int > MP [2];

long long pw(long long a, long long p)
{
	long long res = 1LL;
	for (long long i = 1; i <= p; i ++)
	{
		res *= a;
		if (res >= n) break;
	}
	return res;
}

int solve(long long x, long long y, int move)
{
	if (MP[move].count(make_pair(x, y)) != 0) return MP[move][make_pair(x, y)];
	if (y == 1LL)
	{
		bool have[3];
		have[0] = have[1] = have[2] = false;
		if (x * x >= n)
		{
			if (x < n && (n - x) % 2 == 0LL) 
				have[move] = true; else 
				have[1 - move] = true;
		}
		if (x * x < n && x + 1LL < n) have[solve(x + 1, y, 1 - move)] = true;
		if (x * x < n) have[solve(x, y + 1, 1 - move)] = true;

		int res = 1 - move;
		if (have[move]) res = move; else
		if (have[2]) res = 2;
		MP[move][make_pair(x, y)] = res;
		return res;
	} else
	{
		if (x == 1LL)
		{
			if (pw(2LL, y) >= n) {MP[move][make_pair(x, y)] = 2; return 2;}
			bool have[3];
			have[0] = have[1] = have[2] = false;
			if (pw(2LL, y) < n) have[solve(x + 1, y, 1 - move)] = true;
			if (pw(x, y + 1) < n) have[solve(x, y + 1, 1 - move)] = true;
			int res = 1 - move;
			if (have[move]) res = move; else
			if (have[2]) res = 2;
			MP[move][make_pair(x, y)] = res;
			return res;
		} else
		{
			bool have[3];
			have[0] = have[1] = have[2] = false;
			if (pw(x + 1, y) < n) have[solve(x + 1, y, 1 - move)] = true;
			if (pw(x, y + 1) < n) have[solve(x, y + 1, 1 - move)] = true;

			int res = 1 - move;
			if (have[move]) res = move; else
			if (have[2]) res = 2;
			MP[move][make_pair(x, y)] = res;
			return res;
		}
	}
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> a >> b >> n;
	int res = solve(a, b, 0);
	if (res == 0)
		printf("Masha\n"); else
	if (res == 1)
		printf("Stas\n"); else
		printf("Missing\n");
	return 0;
}