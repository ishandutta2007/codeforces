#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a.size())
#define itr(x) x::iterator

#ifdef _DEBUG
#define endline endl
#else
#define endline "\n"
#endif

typedef long long ll;
typedef vector < ll > vll;
typedef vector < vll > vvll;
typedef vector < int > vi;

int n;
vi a;
vll ans[2];
int k;
vector < bool > up, ua;

const ll MD = 1000000007;

#ifdef _DEBUG
bool
#else
void
#endif
input_data()
{
#ifndef _DEBUG
	ios_base::sync_with_stdio(false);
	cin >> n;
#else
	if (!(cin >> n))
	{
		return false;
	}
	cerr << "n = " << n << endline;
#endif
	for (int i = 0; i < 2; ++i)
	{
#ifdef _DEBUG
	cerr << "fail 0 i = " << i << endline;
	cerr << sz(ans[i]) << endline;
#endif
		ans[i].clear();
#ifdef _DEBUG
	cerr << "fail" << endline;
	cerr << sz(ans[i]) << endline;
#endif
		for (int j = 0; j < n; ++j)
		{
			ans[i].pb(0LL);
		}
#ifdef _DEBUG
	cerr << "fail 1 i = " << i << endline;
#endif
	}
	a.resize(n);
	k = 0;
	ua.assign(n, false);
	up.assign(n, false);
	int oldn = n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
#ifdef _DEBUG
		cerr << a[i] << endline;
#endif
		if (a[i] != -1)
		{
			--oldn;
			ua[i] = true;
			up[a[i] - 1] = true;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (!ua[i] && !up[i])
		{
			++k;
		}
	}
	n = oldn;
	ll cur_m = 1LL;
	ans[0][0] = 1LL;
	for (int i = 1; i <= n; ++i)
	{
		cur_m = (cur_m * i) % MD;
		ans[i & 1][0] = cur_m;
		for (int j = 1; j <= min(i, k); ++j)
		{
			ans[i & 1][j] = (ans[i & 1][j - 1] + cur_m - ans[(i - 1) & 1][j - 1] + MD) % MD;
		}
	}
	ll res = (k == 0) ? ans[n & 1][0] : (ans[n & 1][k] - ans[n & 1][k - 1] + MD) % MD;
	cout << res << endline;
#ifdef _DEBUG
	return true;
#endif
}

int main()
{
#ifdef _DEBUG
	while (input_data()) {}
#else
	input_data();
#endif
	return 0;
}