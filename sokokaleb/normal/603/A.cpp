#include <bits/stdc++.h>
using namespace std;

#define N 100005
int dp[N][3][2];
int arr[N], n;
string s;

int f(int pos, int mode, int lst)
{
	int &res = dp[pos][mode][lst];
	if (res != -1) return res;
	if (pos == n) return res = 0;
	res = f(pos + 1, mode, lst);
	if (mode != 2)
		res = max(res, f(pos, mode + 1, lst));
	int now = (mode&1) ^ arr[pos];
	if (now ^ lst)
		res = max(res, f(pos + 1, mode, now) + 1);
	return res;
}

int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; ++i)
		arr[i] = s[i] - '0';
	memset(dp, -1, sizeof(dp));
	int ans = 0;
	for (int i = 0; i < n; ++i)
		ans = max(ans, f(i + 1, 0, arr[i]) + 1);
	cout << ans << "\n";
	return 0;
}