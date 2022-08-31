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
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

// ========================================================================= //

const int N = 1000179;

int n, k, p[N];
bool vis[N];
vector < int > w;

bool solve(int k)
{
	if (k*2 > n)
		k = n - k;
	vector < ipair > ww;
	for (int x : w)
	{
		if (ww.empty() || ww.back().X != x)
			ww.emplace_back(x, 1);
		else
			++ww.back().Y;
	}
	sort(ww.begin(), ww.end(), [](ipair a, ipair b){return a.X*a.Y < b.X*b.Y;});
	static bool d[N], nd[N];
	d[0] = true;
	int ss = 0;
	for (auto pp : ww)
	{
		int x = pp.X, cnt = pp.Y;
		int xc = x*cnt;
		ss += xc;
		ss = min(ss, k);
		static int tt[N];
		for (int i = 0; i < x; ++i)
			tt[i] = -IINF;
		int ix = 0;
		for (int i = 0; i <= ss; ++i, ++ix)
		{
			if (ix == x) ix = 0;
			if (d[i])
				tt[ix] = i;
			nd[i] = (tt[ix] >= i - xc);
		}
		memcpy(d, nd, sizeof(bool)*(ss+1));
		if (d[k])
			return true;
	}
	return false;
}

int main()
{
    ios::sync_with_stdio(false);

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", p + i);
		--p[i];
	}

	for (int i = 0; i < n; ++i)
	{
		if (vis[i])
			continue;
		int j = i, cnt = 0;
		while (!vis[j])
		{
			vis[j] = true;
			++cnt;
			j = p[j];
		}
		w.push_back(cnt);
	}
	sort(w.begin(), w.end());

	int kk = k;
	int ans1 = 0, ans2 = 0;

	if (solve(k))
		ans1 = k;
	else
		ans1 = k + 1;

	for (int x : w)
	{
		int k1 = min(kk, x/2);
		ans2 += k1*2;
		kk -= k1;
		if (kk == 0)
			break;
	}
	for (int x : w)
	{
		if (kk > 0 && x % 2 == 1)
		{
			--kk;
			++ans2;
		}
	}

	cout << ans1 << " " << ans2 << "\n";

    return 0;
}