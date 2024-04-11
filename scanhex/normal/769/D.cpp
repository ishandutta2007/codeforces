#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <ctime>

using namespace std;
typedef long long nagai;

const int MX = 20001;
const int MX1 = 10001;

int main()
{
//	auto kek = clock();
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> cnt(MX1);
	for (int i = 0; i < n; ++i)
	{
		int x;
		scanf("%d", &x);
		++cnt[x];
	}
	vector<bool> good(MX);
	for (int i = 0; i < MX; ++i)
	{
		int c = 0;
		for (int j = 0; j < 20; ++j)
			if (i >> j & 1)
				++c;
		good[i] = c == k;
	}
	nagai ans = 0;
	for (int i = 0; i < MX1; ++i)
		for (int j = i; j < MX1; ++j)
			if (good[i ^ j])
				if (i != j)
					ans += 1LL * cnt[i] * cnt[j];
				else
					ans += 1LL * cnt[i] * (cnt[i] - 1) / 2;
	cout << ans << endl;
//	cerr << clock() - kek << endl;
}