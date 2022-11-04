#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pb push_back
#define F first
#define S second
#define mp make_pair

#define int long long

int precalc[] = {1, 0, 1, 2, 9, 44};

int calc_ans(int n, int k)
{
	int ans = 1;
	for (int i = 0; i < k; ++i)
		ans *= (n - i);
	for (int i = 0; i < k; ++i)
		ans /= (i + 1);
	ans *= precalc[k];
	return ans;
}

signed main()
{
	int n, k;
	cin >> n >> k;
	int res = 0;
	for (int i = 0; i <= k; ++i)
		res += calc_ans(n, i);
	cout << res << endl;
}