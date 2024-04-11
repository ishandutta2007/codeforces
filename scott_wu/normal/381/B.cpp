#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <set>

using namespace std;
typedef long long ll;

int cnt[5100];

int main()
{
	int m;
	int hi = 0;
	
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int x; cin >> x;
		cnt[x]++;
		
		hi = max (hi, x);
	}
	
	int ans = 1;
	for (int i = 0; i < hi; i++)
		ans += min (2, cnt[i]);
	
	cout << ans << "\n";
	for (int i = 0; i <= hi; i++)
		if (cnt[i])
			cout << i << " ";
	for (int i = hi - 1; i >= 0; i--)
		if (cnt[i] > 1)
			cout << i << " ";
	cout << "\n";
	return 0;
}