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
const int maxn = 2e5 + 5;
int t[maxn], save[maxn], state[maxn];
bool cmp(const int &a, const int &b)
{
	return save[a] < save[b];
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n, h, m, k;
	cin >> n >> h >> m >> k;
	int asd;
	for(int i = 1; i <= n; i ++)
	{
		cin >> asd >> save[i];
		if(save[i] >= m / 2)
			save[i] -= m / 2;
		state[i] = i;
	}
	sort(state + 1, state + n + 1, cmp);
	for(int i = 1; i <= n; i ++)
	{
		t[i] = save[state[i]];
		t[n + i] = t[i] + m / 2;
	}
	int mn = 2e9, mnt = 0, r = 1;
	for(int i = 1; i <= n; i ++)
	{
		for(; r <= n + n && t[r] < t[i] + k; r ++);
		int now = r - i - 1;
		if(now < mn)
		{
			mn = now;
			mnt = t[i];
		}
	}
	int ans = mnt + k;
	if(ans >= m / 2)
		ans -= m / 2;
	cout << mn << " " << ans << endl;
	for(int i = 1; i <= n + n; i ++)
		if(t[i] > mnt && t[i] < mnt + k)
			cout << (i <= n ? state[i] : state[i - n]) << " ";
	cout << endl;
	
	return 0;
}