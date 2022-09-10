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

const int N = 1e6+7;

int n;

string s;

int nast[N][3];
int poprz[N][3];

int last[3];

string lewo;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> s;
	n = siz(s);
	s = '#' + s;

	for(int i = 1; i <= n+1; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			poprz[i][j] = last[j];
		}

		if(i<=n)
			last[s[i]-'a'] = i;
	}

	last[0] = last[1] = last[2] = n+1;

	for(int i = n; i >= 0; --i)
	{
		for(int j = 0; j < 3; ++j)
		{
			nast[i][j] = last[j];
		}

		if(i>=1)
			last[s[i]-'a'] = i;
	}

	int l = 0, r = n+1;

	while(l<r)
	{
		int best = -1;
		int let = -1;

		for(int i = 0; i < 3; ++i)
		{	
			if(nast[l][i]<poprz[r][i])
			{
				int curr = poprz[r][i] - nast[l][i];

				if(curr>best)
				{
					let = i;
					best = curr;
				}
			}
		}

		if(best==-1)
			break;

		lewo += char('a'+let);
		l = nast[l][let];
		r = poprz[r][let];
	}

	string prawo = lewo;
	reverse(ALL(prawo));

	if(l+1<r)
	{
		string ans = lewo + s[l+1] + prawo;
		cout << ans << endl;
	}
	else
	{
		string ans = lewo + prawo;
		cout << ans << endl;
	}
}