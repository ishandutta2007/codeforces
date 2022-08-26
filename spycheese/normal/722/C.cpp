#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const ll MOD = 1000000007;
const double EPS = 1e-9;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};

// ========================================================================= //

const int N = 100179;

int n;
ll a[N], s[N];
set < int > b;
multiset < ll > ans;

int main()
{
    ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		s[i + 1] = s[i] + a[i];
	}
	b.insert(-1);
	b.insert(n);
	ans.insert(s[n]);

	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		--x;
		auto it = b.lower_bound(x);
		int w2 = *it;
		--it;
		int w1 = *it;
		b.insert(x);
		ans.erase(ans.find(s[w2] - s[w1 + 1]));
		ans.insert(s[w2] - s[x + 1]);
		ans.insert(s[x] - s[w1 + 1]);
		cout << *ans.rbegin() << "\n";
	}

    return 0;
}