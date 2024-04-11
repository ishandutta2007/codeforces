#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <complex>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const int maxn = 5e5 + 5;
int a[maxn], same[maxn];
vector<int> pos[maxn];
int calc(const int &x, const int &l, const int &r)
{
	if(l >= r)
		return 0;
	if(l == r - 1)
		return 1 - same[pos[x][l]] + same[pos[x][l] - 1];
	int mid = l + r >> 1;
	int ans = max(calc(x, l, mid), calc(x, mid, r));
	int now1 = 0, now2 = 0;
	for(int i = l; i < mid; i ++)
		now1 = max(now1, mid - i - same[pos[x][mid]] + same[pos[x][i] - 1]);
	for(int i = mid; i < r; i ++)
		now2 = max(now2, i - mid + 1 - same[pos[x][i]] + same[pos[x][mid] - 1]);
	return max(ans, now1 + now2);
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n, c;
	cin >> n >> c;
	int mx = 0;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		mx = max(mx, a[i]);
		same[i] = same[i - 1] + (a[i] == c);
		pos[a[i]].push_back(i);
	}
	int ans = same[n];
	for(int i = 1; i <= mx; i ++)
		ans = max(ans, same[n] + calc(i, 0, pos[i].size()));
	cout << ans << endl;
	
	return 0;
}