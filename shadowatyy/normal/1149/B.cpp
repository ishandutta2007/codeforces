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

const int L = 257;
const int N = 1e5 + 7;

int n, l1, l2, l3, q;

string s;

int nast[N][26];
int last[26];
int dp[L][L][L];

char s1[L];
char s2[L];
char s3[L];

bitset<L> ok[L][L];

void solve(int p1, int p2, int p3)
{
	if(ok[p1][p2][p3])
		return;

	dp[p1][p2][p3] = inf;

	if(p1)
	{
		solve(p1 - 1, p2, p3);

		if(dp[p1 - 1][p2][p3] != inf)
		{
			int znak = s1[p1] - 'a';
			mini(dp[p1][p2][p3], nast[dp[p1 - 1][p2][p3]][znak]);
		}
	}

	if(p2)
	{
		solve(p1, p2 - 1, p3);

		if(dp[p1][p2 - 1][p3] != inf)
		{
			int znak = s2[p2] - 'a';
			mini(dp[p1][p2][p3], nast[dp[p1][p2 - 1][p3]][znak]);
		}
	}

	if(p3)
	{
		solve(p1, p2, p3 - 1);

		if(dp[p1][p2][p3 - 1] != inf)
		{
			int znak = s3[p3] - 'a';
			mini(dp[p1][p2][p3], nast[dp[p1][p2][p3 - 1]][znak]);
		}
	}

	ok[p1][p2][p3] = 1;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> q >> s;

	s = '#' + s;

	for(int i = 0; i < 26; ++i)
	{
		last[i] = inf;
	}

	for(int i = n; i >= 0; --i)
	{
		for(int j = 0; j < 26; ++j)
		{
			nast[i][j] = last[j];
		}

		if(i)
			last[s[i] - 'a'] = i;
	}

	dp[0][0][0] = 0;
	ok[0][0][0] = 1;

	while(q--)
	{
		char t;
		cin >> t;

		if(t == '+')
		{
			int ind;
			char c;
			cin >> ind >> c;

			if(ind == 1)
				s1[++l1] = c;
			else if(ind == 2)
				s2[++l2] = c;
			else
				s3[++l3] = c;
		}
		else
		{
			int ind;
			cin >> ind;

			if(ind == 1)
			{
				for(int i = 0; i <= l2; ++i)
				{
					for(int j = 0; j <= l3; ++j)
					{
						ok[l1][i][j] = 0;
					}
				}

				--l1;
			}
			else if(ind == 2)
			{
				for(int i = 0; i <= l1; ++i)
				{
					for(int j = 0; j <= l3; ++j)
					{
						ok[i][l2][j] = 0;
					}
				}

				--l2;
			}
			else
			{
				for(int i = 0; i <= l1; ++i)
				{
					for(int j = 0; j <= l2; ++j)
					{
						ok[i][j][l3] = 0;
					}
				}

				--l3;
			}
		}

		solve(l1, l2, l3);

		if(dp[l1][l2][l3] == inf)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
}