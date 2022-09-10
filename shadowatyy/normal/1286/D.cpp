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

const int mod = 998244353;
const int N = 1<<17;

int n, inv100;

int x[N];
int v[N];
int p[N];
int ban[N][2][2];

int fpow(int a, int b)
{	
	int res = 1;

	while(b)
	{
		if(b&1)
			res = (ll)res*a%mod;

		b /= 2;
		a = (ll)a*a%mod;
	}

	return res;
}

struct depe
{
	int dp[2][2];

	depe()
	{
		dp[0][0] = dp[1][1] = dp[0][1] = dp[1][0] = 0;
	}
};

depe sub[2*N];

depe merge(depe A, depe B, int m)
{
	depe C;

	for(int i = 0; i < 2; ++i)
	{
		for(int j = 0; j < 2; ++j)
		{
			for(int k = 0; k < 2; ++k)
			{
				if(ban[m][j][k])
					continue;

				for(int l = 0; l < 2; ++l)
				{
					C.dp[i][l] += (ll)A.dp[i][j]*B.dp[k][l]%mod;
					C.dp[i][l] %= mod;
				}
			}
		}
	}

	return C;
}

VPII ans;

struct event
{
	int i, typ, dist, speed;
};

bool operator<(const event &a, const event &b)
{
	return (ll)a.dist*b.speed<(ll)b.dist*a.speed;
}

bool operator!=(const event &a, const event &b)
{
	return a<b || b<a;
}

vector<event> E;

void update(int i, int v = 1, int l = 0, int r = N-1)
{
	if(r<i || l>i+1)
		return;

	if(l==r)
		return;

	update(i, 2*v, l, (l+r)/2);
	update(i, 2*v+1, (l+r)/2+1, r);
	sub[v] = merge(sub[2*v], sub[2*v+1], (l+r)/2);
}

void build(int v = 1, int l = 0, int r = N-1)
{
	if(l==r)
	{
		sub[v].dp[1][1] = (ll)p[l]*inv100%mod;
		sub[v].dp[0][0] = (1-sub[v].dp[1][1]+mod)%mod;
		return;
	}

	build(2*v, l, (l+r)/2);
	build(2*v+1, (l+r)/2+1, r);
	sub[v] = merge(sub[2*v], sub[2*v+1], (l+r)/2);
}

depe query(int a, int b, int v = 1, int l = 0, int r = N-1)
{
	if(a<=l && r<=b)
		return sub[v];

	int m = (l+r)/2;

	if(b<=m)
		return query(a, b, 2*v, l, m);
	else if(a>m)
		return query(a, b, 2*v+1, m+1, r);
	else	
		return merge(query(a, b, 2*v, l, (l+r)/2), query(a, b, 2*v+1, (l+r)/2+1, r), (l+r)/2);
}

int sumuj(depe A)
{
	int ans = 0;

	for(int i = 0; i < 2; ++i)
	{
		for(int j = 0; j < 2; ++j)
		{
			ans += A.dp[i][j];
			ans %= mod;
		}
	}

	return ans;
}

int dziel(int a, int b)
{
	return (ll)a * fpow(b, mod - 2) % mod;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	//debug(dziel(1, 8));

	inv100 = fpow(100, mod-2);

	cin >> n;

	if(n == 1)
	{
		cout << 0 << endl;
		return 0;
	}

	for(int i = 1; i <= n; ++i)
	{
		cin >> x[i] >> v[i] >> p[i];
	}

	for(int i = 1; i < n; ++i)
	{
		int sum = v[i]+v[i+1];
		int dist = x[i+1]-x[i];
		int diff = abs(v[i]-v[i+1]);

		E.pb((event){i, 1, dist, sum});

		if(v[i]>v[i+1])
			E.pb((event){i, 2, dist, diff});
		else if(v[i]<v[i+1])
			E.pb((event){i, 3, dist, diff});
	}

	build();

	sort(ALL(E));

	/*for(auto it:E)
	{
		debug(it.dist, it.speed);
	}*/

	ans.eb(dziel(E[0].dist, E[0].speed), 1);

	//auto x = query(1, n);
	//debug(x.dp[0][1]);

	for(int i = 0; i < siz(E); ++i)
	{
		auto it = E[i];

		//debug(it.i, it.typ);

		if(it.typ==1)
		{
			ban[it.i][1][0] = 1;
		}
		else if(it.typ==2)
		{
			ban[it.i][1][1] = 1;
		}
		else
		{
			ban[it.i][0][0] = 1;
		}

		update(it.i);

		//auto x = query(1, n);
		//debug(x.dp[0][1]);

		//debug(sumuj(query(1, n)));

		if(i+1<siz(E))
			ans.eb(dziel(E[i+1].dist, E[i+1].speed), sumuj(query(1, n)));
		else
			ans.eb(0, sumuj(query(1, n)));
	}

	int res = 0;
	int mam = 0;

	reverse(ALL(ans));

	for(auto it:ans)
	{
		int prob = (it.nd-mam+mod)%mod;
		res += (ll)it.st*prob%mod;
		res %= mod;
		mam += prob;
		mam %= mod;
	}

	cout << res << endl;
}