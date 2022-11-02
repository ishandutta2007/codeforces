#include <iostream>
using namespace std;

const int N = 100011;
int dp[N];
int p[N];

int solve(int l, int r, int mid)
{
	if(l == mid)
		return p[r] - p[mid];
	else if(r == mid)
		return p[mid] - p[l];
	return max(p[r] - p[mid], p[mid] - p[l]);
}

int main()
{
	ios :: sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	
	int cnt = 0;
	for(int i = 0; i < n; i ++)
		if(s[i] == '0')
			p[++ cnt] = i + 1;
	k ++;

	int mid = 1;
	int ans = 0x3f3f3f3f;
	for(int i = k; i <= cnt; i ++)
	{
		if(mid < i - k + 1)
			mid ++;
		while(mid < i && solve(i - k + 1, i, mid + 1) < solve(i - k + 1, i, mid))
			mid ++;
		//cout << i << ' ' << mid << '\n';
		ans = min(ans, solve(i - k + 1, i, mid));
	}
	cout << ans << '\n';
	return 0;
}