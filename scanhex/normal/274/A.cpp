#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a.begin(), a.end());
	set<int> ans;
	for (int i = 0; i < n; ++i) 
	{
		if (a[i] % k != 0 || a[i] % k == 0 && ans.find(a[i] / k) == ans.end())
			ans.insert(a[i]);
	}
	cout << ans.size();
}