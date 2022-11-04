#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define all(v) v.begin(), v.end()
#define len(v) ((int)v.size())
#define pb push_back
#define int ll

void usefiles(const string &s)
{
#ifndef LOCAL
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
#endif
}

template<class t1, class t2>
inline bool cmin(t1 &a, const t2 &b)
{
	if (a > b)
	{
		a = b;
		return true;
	}
	return false;
}

template<class t1, class t2>
inline bool cmax(t1 &a, const t2 &b)
{
	if (a < b)
	{
		a = b;
		return true;
	}
	return false;
}

void run();

signed main()
{
	// usefiles("post");
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	run();
}

int mex(vector<int> v)
{
	sort(all(v));
	v.resize(unique(all(v)) - v.begin());
	for (int i = 0; i < len(v); ++i)
		if (i != v[i])
			return i;
	return len(v);
}

void run()
{
	int a, b;
	cin >> a >> b;
	vector<int> resa, resb;
	int n = a + b;
	vector<int> ans;
	for (int i = 1; i < 1e5; ++i)
		if (n >= i)
		{
			ans.pb(i);
			n -= i;
		}
	reverse(all(ans));
	for (auto &x : ans)
	{
		if (x <= a)
		{
			a -= x;
			resa.pb(x);
		}
		else if (x <= b)
		{
			b -= x;
			resb.pb(x);
		}
	}
	sort(all(resa));
	sort(all(resb));
	cout << len(resa) << endl;
	for (auto &x : resa)
		cout << x << " ";
	cout << endl;
	cout << len(resb) << endl;
	for (auto &x : resb)
		cout << x << " ";
	cout << endl;
}