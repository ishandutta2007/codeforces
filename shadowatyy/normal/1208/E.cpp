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

const int N = 1<<20;
#define int ll

int n, w, d;

int a[N];
PII sub[2*N];
int ans[N];
vector<pair<PII, int> > S;

void insert(int a, int v)
{
	a += N;
	sub[a] = mp(v, a-N);
	a /= 2;

	while(a)
	{
		sub[a] = max(sub[2*a], sub[2*a+1]);
		a /= 2;
	}
}

PII query(int a, int b, int v = 1, int l = 0, int r = N-1)
{
	if(a>r || l>b)
		return mp(-inf, -inf);

	if(a<=l && r<=b)
		return sub[v];

	return max(query(a, b, 2*v, l, (l+r)/2), query(a, b, 2*v+1, (l+r)/2+1, r));
}

void rec(int a, int b, int l, int r) //pokryj a, b przy uzyciu l, r
{
	if(a>b)
		return;

	debug(a, b, l, r);
	auto it = query(l, r);
	int val = it.st;
	int ind = it.nd;
	debug(val, ind);
	int lewo = ind-1;
	int prawo = d-ind;
	int L = max(a, lewo+1);
	int R = min(b, w-prawo);
	debug(L, R);
	//ans[L] += val;
	//ans[R+1] -= val;
	S.eb(mp(L, R), val);
	rec(a, L-1, l, ind-1);
	rec(R+1, b, ind+1, r);
}

void solve()
{
	cin >> d;

	for(int i = 1; i <= d; ++i)
	{
		cin >> a[i];
		insert(i, a[i]);
	}

	rec(1, w, 1, d);

	int luz = w-d;
	int lewo = luz+1;
	int prawo = w-luz;

	for(auto it:S)
	{
		if(it.nd>0)
		{
			if(it.st.st<=it.st.nd)
			{
				ans[it.st.st] += it.nd;
				ans[it.st.nd+1] -= it.nd;
			}			
		}
		else
		{
			int l = max(it.st.st, lewo);
			int r = min(it.st.nd, prawo);

			if(l<=r)
			{
				ans[l] += it.nd;
				ans[r+1] -= it.nd;
			}
		}
	}

	debug("OK");
	S.clear();
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> w;

	while(n--)
		solve();

	for(int i = 1; i <= w; ++i)
	{
		ans[i] += ans[i-1];
		cout << ans[i] << " ";
	}

	cout << endl;
}