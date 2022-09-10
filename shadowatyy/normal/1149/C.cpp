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

const int N = 1 << 18;

int n, q;

string s;

VI deps;

int lazy[2 * N];
int sub[2 * N][3][3];
int wsp[3] = {1, -2, 1};

void update(int v, int c)
{
	for(int i = 0; i < 3; ++i)
	{
		int sum_wsp = 0;

		for(int j = i; j < 3; ++j)
		{
			sum_wsp += wsp[j];
			sub[v][i][j] += sum_wsp * c;
		}
	}

	lazy[v] += c;
}	

void push(int v)
{
	if(lazy[v])
	{
		update(2 * v, lazy[v]);
		update(2 * v + 1, lazy[v]);
		lazy[v] = 0;
	}
}

void merge(int v)
{
	for(int i = 0; i < 3; ++i)
	{
		for(int j = i; j < 3; ++j)
		{
			sub[v][i][j] = max(sub[2 * v][i][j], sub[2 * v + 1][i][j]);

			for(int k = i; k < j; ++k)
			{
				maxi(sub[v][i][j], sub[2 * v][i][k] + sub[2 * v + 1][k + 1][j]);
			}
		}
	}
}

void insert(int a, int b, int c, int v = 1, int l = 0, int r = N - 1)
{
	if(a > r || l > b)
		return;

	if(a <= l && r <= b)
	{
		update(v, c);
		return;
	}

	push(v);
	int mid = (l + r) / 2;
	insert(a, b, c, 2 * v, l, mid);
	insert(a, b, c, 2 * v + 1, mid + 1, r);
	merge(v);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> q >> s;

	//swap(s[5], s[6]);
	//swap(s[4], s[3]);
	//swap(s[5], s[3]);
	//swap(s[6], s[3]);

	int dep = 0;

	deps.pb(dep);

	for(auto it:s)
	{
		if(it == '(')
			++dep;
		else
			--dep;

		deps.pb(dep);
	}

	s = '#' + s;

	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			for(int k = 0; k < 3; ++k)
			{
				sub[i][j][k] = -inf;
			}
		}
	}

	for(int i = 0; i < 2 * n - 1; ++i)
	{
		update(i + N, deps[i]);
	}

	for(int i = N - 1; i >= 1; --i)
	{
		merge(i);
	}

	cout << sub[1][0][2] << endl;

	while(q--)
	{
		int l, r;
		cin >> l >> r;

		if(l > r)
			swap(l, r);

		if(s[l] == '(')
			insert(l, r - 1, -2);
		else
			insert(l, r - 1, +2);

		swap(s[l], s[r]);

		cout << sub[1][0][2] << endl;
	}
}