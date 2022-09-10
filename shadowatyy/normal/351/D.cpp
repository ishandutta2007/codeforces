//shadowatyy
#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define VI vector<int>
#define VPII vector<PII>
#define LL long long
#define LD long double
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define ll LL
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define siz(c) (int)(c).size()
const int inf = 1e9+7;
const ll INF = 1e18L+7;

#define sim template<class n
sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.f << ", " << x.s << ">";}
sim> auto operator << (ostream &p, n y) ->
typename enable_if<!is_same<n, string>::value, decltype(y.begin(), p)>::type 
{int o = 0; p << "{"; for(auto c: y) {if(o++) p << ", "; p << c;} return p << "}";}
void dor() {cerr << endl;}
sim, class...s> void dor(n p, s...y) {cerr << p << " "; dor(y...);}
sim, class s> void mini(n &p, s y) {if(p>y) p = y;}
sim, class s> void maxi(n &p, s y) {if(p<y) p = y;}
#ifdef DEB
#define debug(...) dor(__FUNCTION__, ":", __LINE__, ": ", __VA_ARGS__)
#else
#define debug(...)
#endif 

#define I(x) #x " =", (x), " "

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

const int N = 1<<17;

int n, q;

int a[N];

VI wyst[N];

int pocz[N];

int rozne[N];

int fen[N];

int l[N];
int r[N];

VI lewo[N];

int last[N];
int nast[N];

int pyk[N];

int load[2*N];

void ins(int a, int v)
{
	a += N;
	load[a] = v;
	a /= 2;

	while(a)
	{
		load[a] = max(load[2*a], load[2*a+1]);
		a /= 2;
	}
}

int que(int a, int b)
{
	int res = 0;
	a += N-1;
	b += N+1;

	while(a<b-1)
	{
		if(a%2==0)
			maxi(res, load[a+1]);

		if(b%2==1)
			maxi(res, load[b-1]);

		a /= 2;
		b /= 2;
	}

	return res;
}

void add(int x, int v)
{
	while(x<=n)
	{
		fen[x] += v;
		x += x&-x;
	}
}

int ask(int x)
{
	int res = 0;

	while(x)
	{
		res += fen[x];
		x -= x&-x;
	}

	return res;
}

int query(int a, int b)
{
	return ask(b) - ask(a-1);
}

bool ok(int a, int b, VI &vec)
{
	if(a+1==b)
		return 1;

	return vec[a+1]-vec[a] == vec[b]-vec[b-1];
}

void go(VI &vec)
{
	int len = siz(vec);
	vec.insert(vec.begin(), 0);
	vec.pb(n+1);

	int r = 1;

	for(int l = 1; l <= len; ++l)
	{
		maxi(r, l);

		while(r+1<=len && ok(l, r+1, vec))
			++r;

		// /int L = vec[l-1]+1;
		int L = vec[l];
		int R = vec[r+1]-1;
		// maxi(pocz[L], R);
		// debug(L, R);

		pyk[L] = R;
	}	
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		wyst[a[i]].pb(i);
	}

	for(int i = n; i >= 1; --i)
	{
		nast[i] = last[a[i]];
		last[a[i]] = i;
	}

	for(int i = 0; i < N; ++i)
	{
		if(!wyst[i].empty())
			go(wyst[i]);
	}

	for(int i = 0; i < N; ++i)
	{
		if(siz(wyst[i])>2)
		{
			add(wyst[i][1], 1);
			ins(wyst[i][1], pyk[wyst[i][1]]);
			//S.insert(pyk[wyst[i][1]]);
		}
	}

	cin >> q;

	for(int i = 1; i <= q; ++i)
	{
		cin >> l[i] >> r[i];
		lewo[l[i]].pb(i);
	}

	for(int i = 1; i <= n; ++i)
	{
		for(auto it:lewo[i])
		{
			rozne[it] = query(l[it], r[it]);

			// if(S.empty() || *S.rbegin() < r[it])
			if(que(l[it], r[it]) < r[it])
				++rozne[it];
		}

		add(i, -1);
		ins(i, 0);
		// S.erase(S.find(pyk[i]));

		if(nast[i])
		{
			add(nast[i], 1);
			// S.insert(pyk[nast[i]]);
			ins(nast[i], pyk[nast[i]]);
		}
	}

	for(int i = 1; i <= q; ++i)
	{
		cout << rozne[i] << endl;
	}
}