#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<pair<ll,ll>> vec;
const int Max = 4e3 + 5;
const int Mod = 998244353;
 
int n, k;
int a[Max][Max];
ll cur[Max], pre[Max];
 
void Try(int l, int r, int i, int j)
{
	if (r < l)
		return;
	int mid = l + r >> 1;
	ll best = 2e9;
	ll idx = 0;
	for (int k = max(mid,i); k <= j; k++)
	{
		ll val = a[mid][k] + pre[k + 1];
		if (val <= best)
			best = val, idx = k;
	}
	cur[mid] = best;
	Try(mid + 1, r, idx, j);
	Try(l, mid - 1, i, idx);
}
 
int main()
{
	cin >> n >> k;
	getchar();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++,getchar())
			a[i][j] = (getchar() - '0');
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			a[i][j] += a[i][j - 1];
	for (int j = 0; j < n; j++)
		for (int i = j-1; i >= 0; i--)
			a[i][j] += a[i + 1][j];
	for (int i = 0; i < n; i++)
		pre[i] = 1e9;
	for (int i = 0; i < k; i++)
	{
		Try(0, n, 0, n - 1);
		swap(pre, cur);
	}
	cout << pre[0] << endl;
	return 0;
}