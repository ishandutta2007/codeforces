#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
using ll = long long;

const int N = 300005;
const int mod = 998244353;
int add(int a, int b)
{
	 a += b;
	 if (a >= mod)
		 return a - mod;
	 return a;
}
int mult(int a, int b)
{
	 return (nagai)a * b % mod;
}
int inv(int a)
{
	int b = mod - 2;
	int c = 1;
	while (b)
	{
		 if (b & 1)
			 c = mult(c, a);
		 a = mult(a, a);
		 b /= 2;
	}
	return c;
}
#define div aesnuh
int div(int a, int b)
{
	 return mult(a, inv(b));
}
vector<int> g[N];
int dp[N][3];
int mx[N][2];

void d(int u, int p)
{
	vector<int> ch;
	for (int v : g[u])
		if (v != p)
		{
			d(v, u);
			ch.push_back(v);
		}
	if (ch.size() == 0)
	{
		dp[u][0] = 1;
		dp[u][2] = 1;
//		dp[u][1] = 1;
		return;
	}
	/*
	int sum = 0;
	for (int x : ch)
		sum += mx[x][1];
	mx[u][0] = sum;
	// 0 - ne zanyat
	// 1 - zanyat 
	mx[u][1] = sum;
	for (int x : ch)
	{
		int val =  1 + sum - mx[x][1] + mx[x][0];
		mx[u][1] = max(mx[u][1], val);
	}
	*/
//	dp[u][0] = 0; // empty
//	dp[u][1] = 1; // empty
	int mul = 1;
	for (int x : ch)
	{
		mul = mult(mul, add(dp[x][2], mult(2, dp[x][1])));
	}
	dp[u][0] = add(dp[u][0], mul);
	for (int x : ch)
	{
		int val = div(mul, add(dp[x][2], mult(2, dp[x][1])));
		val = mult(val, dp[x][0]);
//		cerr << val << '\n';
		dp[u][1] = add(dp[u][1], val);
	}
	int mul1 = 1;
	for (int x : ch)
		mul1 = mult(mul1, add(dp[x][2], dp[x][1]));
//	cerr << u << ' ' << dp[u][0] << ' ' << dp[u][1] << ' ' << dp[u][2] << '\n';
	dp[u][2] = mul1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	d(0, -1);
	int ans = dp[0][1];
	cout << add(dp[0][2], ans) << '\n';
	return 0;
}