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

const int N = 2e5+7;

int n, m, k, curr;

int x[N];
int y[N];
int deg[N];
int ans[N];
int del[N];

queue<int> Q;

set<PII> usun;

VI G[N];

void go()
{
	while(!Q.empty())
	{
		int v = Q.front();
		Q.pop();

		//debug(v);

		for(auto it:G[v])
		{
			if(!usun.count(mp(it, v)) && !usun.count(mp(v, it)) && (--deg[it])<k && !del[it])
			{
			//	debug("huj", it);
				del[it] = 1;
				Q.push(it);
				++curr;
			}
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> k;

	for(int i = 1; i <= m; ++i)
	{
		cin >> x[i] >> y[i];
		++deg[x[i]];
		++deg[y[i]];
		G[x[i]].pb(y[i]);
		G[y[i]].pb(x[i]);
	}

	for(int i = 1; i <= n; ++i)
	{
		if(deg[i]<k)
		{
			del[i] = 1;
			Q.push(i);
			++curr;
		}
	}

	debug(I(deg[1]));

	go();

		debug(I(deg[1]));


	for(int i = m; i >= 1; --i)
	{
		ans[i] = n-curr;

		debug(x[i], y[i]);

				usun.insert({x[i], y[i]});


		if(del[x[i]] || del[y[i]])
			continue;

		--deg[x[i]];
		--deg[y[i]];

		//debug(I(x[i]), I(deg[x[i]]), I(k));
		//		debug(I(y[i]), I(deg[y[i]]), I(k));

		if(deg[x[i]]<k && !del[x[i]])
		{
			debug(x[i]);
			del[x[i]] = 1;
			Q.push(x[i]);
			++curr;
		}

		if(deg[y[i]]<k && !del[y[i]])
		{
			debug(y[i]);
			del[y[i]] = 1;
			Q.push(y[i]);
			++curr;
		}

		go();

			debug(curr);
	}

	for(int i = 1; i <= m; ++i)
	{
		cout << ans[i] << endl;
	}
}