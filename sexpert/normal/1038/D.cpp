#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> wt;
	for(int i = 0; i < n; i++)
	{
	    int x;
	    cin >> x;
	    wt.push_back(x);
	}
	sort(wt.begin(), wt.end());
	long long ans = 0;
	if(n == 1) ans = wt[0];
	else
	{
	    ans += wt[n - 1];
	    ans -= wt[0];
	    for(int i = 1; i <= n - 2; i++) ans += abs(wt[i]);
	}
	cout << ans << endl;
}