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

typedef vector < int > vi;
typedef vector < vi > vvi;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a.size())
#define itr(x) x::iterator

const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef vector < ll > vll;

ll gcd(ll a, ll b)
{
	if (a < b)
	{
		return gcd(b, a);
	}
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a % b);
}

int n;
vll a;
ll p, q;

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
	p = 0LL;
	q = (ll) n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	ll csum = 0LL;
	for (int i = 0; i < n; ++i)
	{
#ifdef _DEBUG
		cerr << "csum = " << csum << endline;
		cerr << 2LL * ((ll) i * a[i] - csum) << endline;
#endif
		p += 2LL * ((ll) i * a[i] - csum) + ((a[i] >= 0) ? a[i] : -a[i]);
		csum += a[i];
	}
	ll g = gcd(p, q);
	p /= g;
	q /= g;
	cout << p << " " << q << endline;
#ifdef _DEBUG
	return true;
#endif
}

int main()
{
#ifdef _DEBUG
	while (input_data()) {
#else
	input_data();
#endif
#ifdef _DEBUG
	}
#endif
	return 0;
}