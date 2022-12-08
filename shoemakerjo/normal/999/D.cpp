#include <bits/stdc++.h>

using namespace std;

#define int long long

int nums[200010];
int orig[200010];
 main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		int a; cin >> a; nums[a % m]++;
		orig[i] = a;
	}
	int ans = 0;
	set<int> less;
	for (int i = 0; i < m; i++) {
		if (nums[i] < n/m) less.insert(i);
	}
	for(int i = 0; i < n; i++)
	{
		int cmod = orig[i]%m;
		if (nums[cmod] <= n/m) continue;
		auto nx = less.upper_bound(cmod);
		if (nx == less.end()) nx = less.begin();
		int nval = *nx;
		int diff = nval - cmod;
		if (diff < 0) diff += m;
		ans += diff;
		nums[cmod]--;
		nums[nval]++;
		if (nums[nval] == n/m) less.erase(nval);
		orig[i] += diff;
		
	}
	cout << ans << endl;
	for (int kumar = 0; kumar < n; kumar++) cout << orig[kumar] << ' ';
	cout << endl;
	
}