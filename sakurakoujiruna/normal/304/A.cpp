#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll A[3][3] = {{1, -2, 2}, {2, -1, 2}, {2, -2, 3}};
const ll B[3][3] = {{1, 2, 2}, {2, 1, 2}, {2, 2, 3}};
const ll C[3][3] = {{-1, 2, 2}, {-2, 1, 2}, {-2, 2, 3}};
ll n = 1e9, ans = 0;
void dfs(ll a[3]) {
	if(a[2] > n) return;
	ans += n / a[2]; ll b[3];
	for(int i = 0; i < 3; i ++)
		b[i] = A[i][0] * a[0] + A[i][1] * a[1] + A[i][2] * a[2]; dfs(b);
	for(int i = 0; i < 3; i ++)
		b[i] = B[i][0] * a[0] + B[i][1] * a[1] + B[i][2] * a[2]; dfs(b);
	for(int i = 0; i < 3; i ++)
		b[i] = C[i][0] * a[0] + C[i][1] * a[1] + C[i][2] * a[2]; dfs(b);
}

int main()
{
	ios :: sync_with_stdio(false);
	ll n;
	cin >> n;
	::n = n;
	ll a[3] = {3, 4, 5};
	dfs(a);
	cout << ans << '\n';
	return 0;
}