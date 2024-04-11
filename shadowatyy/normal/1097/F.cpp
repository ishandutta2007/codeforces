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

const int N = 1e5+7;
const int K = 7007;

int n, q;

bitset<K> divs[K];
bitset<K> curr[N];
bitset<K> paths[K]; //[x][y] ile jest sciezek od x do y po wielokrotnosciach

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	for(int i = 1; i < K; ++i)
	{
		paths[i][i] = 1;
	}

	for(int i = 1; i < K; ++i)
	{
		for(int j = i; j < K; j += i)
		{
			divs[j][i] = 1;
		}
	}

	for(int i = K-1; i >= 1; --i)
	{
		for(int j = 1; j < i; ++j)
		{
			if(i%j==0)
				paths[j] ^= paths[i];
		}
	}

	string ans;

	cin >> n >> q;

	for(int i = 0; i < q; ++i)
	{
		int t;
		cin >> t;

		if(t==1)
		{
			int x, v;
			cin >> x >> v;
			curr[x] = divs[v];
		}
		else if(t==2)
		{
			int x, y, z;
			cin >> x >> y >> z;
			curr[x] = (curr[y]^curr[z]);
		}
		else if(t==3)
		{
			int x, y, z;
			cin >> x >> y >> z;
			curr[x] = (curr[y]&curr[z]);
		}
		else if(t==4)
		{
			int x, v;
			cin >> x >> v;
			ans += char('0'+((curr[x]&paths[v]).count())%2);
		}
	}

	cout << ans << endl;
}