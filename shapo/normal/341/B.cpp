#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

#ifdef _DEBUG
#define endline endl
#else
#define endline "\n"
#endif

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a.size())
#define itr(x) x::iterator

typedef vector < int > vi;
typedef vector < vi > vvi;

const int INF = 0x3f3f3f3f;

int n;
vi a;
vi subs;

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
#endif
	a.resize(n);
	subs.clear();
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		itr(vi) it = upper_bound(subs.begin(), subs.end(), a[i]);
		if (it == subs.end())
		{
			subs.pb(a[i]);
		}
		else
		{
			*it = a[i];
		}
	}
	cout << sz(subs) << endline;
#ifdef _DEBUG
	return true;
#endif
}

int main()
{
#ifdef _DEBUG
	while (input_data()) {
	}
#else
	input_data();
#endif
	return 0;
}