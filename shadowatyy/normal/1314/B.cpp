#include <bits/stdc++.h>
using namespace std;

#define PII pair<int, int>
#define VI vector<int>
#define VPII vector<PII>
#define LL long long
#define LD long double
#define f first
#define s second
#define MP make_pair
#define PB push_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, b, e) for (int i = (b); i <= (int)(e); i++)
#define FORD(i, b, e) for (int i = (b); i >= (int)(e); i--)
#define ll long long
#define st f
#define nd s
#define pb PB
#define eb emplace_back
#define mp make_pair				
#define siz(c) SIZ(c)
const int inf = 1e9 + 7;
const LL INF = 1e18L + 7;

#define sim template<class n
sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.f << ", " << x.s << ">";}
sim> auto operator << (ostream &p, n y) ->
typename enable_if<!is_same<n, string>::value, decltype(y.begin(), p)>::type
{int o = 0; p << "{"; for (auto c : y) {if (o++) p << ", "; p << c;} return p << "}";}
void dor() {cerr << endl;}
sim, class...s> void dor(n p, s...y) {cerr << p << " "; dor(y...);}
sim, class s> void mini(n &p, s y) {if (p > y) p = y;}
sim, class s> void maxi(n &p, s y) {if (p < y) p = y;}

#ifdef DEB
#define debug(...) dor(__FUNCTION__, ":", __LINE__, ": ", __VA_ARGS__)
#else
#define debug(...)
#endif

#define I(x) #x " = ", (x), " "
#define A(a, i) #a "[" #i " = ", i, "] = ", a[i], " "

#ifndef LOCAL
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <typename T>
using ordered_set =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#else
#include</Users/dawid/algo/mac/ordered_set>
#endif

const int N = 1<<19;

int n, k;

int ok[N];
int dp[N][2][2];

void solve(int v, int l, int r)
{
	for(int i = 0; i < 2; ++i)
	{
		for(int j = 0; j < 2; ++j)
		{
			dp[v][i][j] = -inf;
		}
	}

	if(l+1==r)
	{
		if(ok[l]!=ok[r])
			dp[v][0][1] = dp[v][1][0] = 1;
		else if(ok[l])
			dp[v][1][1] = 1;
		else
			dp[v][0][0] = 0;

		return;
	}

	solve(2*v, l, (l+r)/2);
	solve(2*v+1, (l+r)/2+1, r);

	for(int a = 0; a < 2; ++a)
	{
		for(int b = 0; b < 2; ++b)
		{
			for(int c = 0; c < 2; ++c)
			{
				for(int d = 0; d < 2; ++d)
				{
					for(int w1 = 0; w1 < 2; ++w1)
					{
						for(int w2 = 0; w2 < 2; ++w2)
						{
							//for(int w3 = 0; w3 < 2; ++w3)
							//{
							int ile = 0;

							if(a|c)
								++ile;

							if(b|d)
								++ile;

							int zos, lost, won;

							if(w1)
							{
								lost = a;
								zos = c;
							}
							else
							{
								lost = c;
								zos = a;
							}

							if(w2)
								won = b;
							else
								won = d;

							if(lost|won)
								++ile;

							maxi(dp[v][zos][lost], dp[2*v][a][b]+dp[2*v+1][c][d]+ile);
							maxi(dp[v][zos][won], dp[2*v][a][b]+dp[2*v+1][c][d]+ile);
						}
					}
				}
			}
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i <= k; ++i)
	{
		int x;
		cin >> x;
		--x;
		ok[x] = 1;
	}

	solve(1, 0, (1<<n)-1);

	int ans = dp[1][0][0];
	maxi(ans, dp[1][1][0]+1);
	maxi(ans, dp[1][0][1]+1);
	maxi(ans, dp[1][1][1]+1);

	cout << ans << endl;
}