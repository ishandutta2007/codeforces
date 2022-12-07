#include <bits/stdc++.h>

using namespace std;

long long C[777][777];

int r, c;
long long total;
long long best = (long long) 1e18, best_z = -1;

void dfs(long long x, long long y, int v1, int v2)
{
	long long diff = abs(x - y);
	if (best <= 1 || diff - C[v1][r] * C[v2][r] >= best)
		return;
		
  if (v1 == r - 1 && v2 == r - 1)
  {
    long long diff = abs(x - y);
    if (diff < best) {
      best = diff;
      best_z = x;
    }
    return;
  }
	if (v1 >= r)
		{
    	long long cur1 = C[v1][r] - C[v1 - 1][r];
		long long sum2 = C[v2][r];
    	dfs(x, y + cur1 * sum2, v1 - 1, v2);
	}
	if (v2 >= r)
	{
		long long sum1 = C[v1][r];
		long long cur2 = C[v2][r] - C[v2 - 1][r];
		dfs(x + sum1 * cur2, y, v1, v2 - 1);
	}
}

char s[12345];
int cntA[12345], cntB[12345];
map<long long, long long> mp;

long long solve(long long x, long long y, int v1, int v2)
{
	long long state = x * 10000 + v1 * 100 + v2;
	if(mp.find(state) != mp.end())
		return mp[state];
		
  long long &res = mp[state];
  long long diff = abs(x - y);
  if (diff - C[v1][r] * C[v2][r] > best) {
    return res = 0;
  }
  if (v1 < r || v2 < r) {
    if (v1 >= cntA[v1 + v2] && v2 >= cntB[v1 + v2]) {
      int sum = v1 + v2;
      v1 -= cntA[sum];
      v2 -= cntB[sum];
      return res = C[v1 + v2][v1]; 
    }
    return res = 0;
  }
	res = 0;
	char c = s[v1 + v2 - 1];
	if (c != 'B')
	{
		long long cur1 = C[v1][r] - C[v1 - 1][r];
		long long sum2 = C[v2][r];
		res += solve(x, y + cur1 * sum2, v1 - 1, v2);
	}
	if (c != 'A')
	{
		long long sum1 = C[v1][r];
		long long cur2 = C[v2][r] - C[v2 - 1][r];
		res += solve(x + sum1 * cur2, y, v1, v2 - 1);
	}
	return res;
}

int main() {
  scanf("%d %d", &r, &c);
  for (int i = 0; i <= 2 * (r + c); i++) {
    for (int j = 0; j <= 2 * (r + c); j++) {
      if (j == 0) C[i][j] = 1; else
      if (i == 0) C[i][j] = 0;
      else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]);
    }
  }
  total = C[r + c][r] * C[r + c][r];
  {
    long long x = 0, y = 0;
    int v1 = r + c, v2 = r + c;
    while (v1 >= r && v2 >= r) {
      if (x > y) {
        long long cur1 = C[v1][r] - C[v1 - 1][r];
        long long sum2 = C[v2][r];
        y += cur1 * sum2;
        v1--;
      } else {
        long long sum1 = C[v1][r];
        long long cur2 = C[v2][r] - C[v2 - 1][r];
        x += sum1 * cur2;
        v2--;
      }
    }
    best = abs(x - y);
  }
  dfs(0, 0, r + c, r + c);
  scanf("%s", s);
  cntA[0] = cntB[0] = 0;
  for (int i = 0; i < 2 * (r + c); i++) {
    cntA[i + 1] = cntA[i] + (s[i] == 'A');
    cntB[i + 1] = cntB[i] + (s[i] == 'B');
  }
  long long ans = solve(0, 0, r + c, r + c);
  cout << ans << endl;
  return 0;
}