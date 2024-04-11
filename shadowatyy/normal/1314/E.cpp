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
const int N = 2027;

int n, k, cnt, maxSum, sum;

int part[N];
int dwa[N];

VI vec;
 
bool checkSum(VI &curr)
{
	int ans = 0;

	for(int j = siz(curr)-1; j >= 0; --j)
	{
		ans += curr[j] * (siz(curr)-j);

		if(ans>n)
			return 0;
	}

	return 1;
}

bool check()
{
	VI curr = vec;

	for(int i = 0; i < k-2; ++i)
	{
		VI nast;

		for(int j = siz(curr)-1; j >= 0; --j)
		{
			for(int x = 0; x < curr[j]; ++x)
			{
				nast.pb(siz(curr)-j);
			}
		}	

		curr = nast;

		if(!checkSum(curr))
			return 0;
	}

	return 1;
}

void rec()
{
	if(!check())
		return;

	++cnt;

	if(sum < maxSum)
	{
		++sum;
		vec.back()++;
		rec();
		--sum;
		vec.back()--;
	}
	
	if(sum + vec.back() <= maxSum)
	{
		sum += vec.back();
		vec.pb(vec.back());
		rec();
		sum -= vec.back();
		vec.pop_back();
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	if(k==1)
	{
		part[0] = 1;

		for(int i = 1; i <= n; ++i)
		{
			for(int j = i; j <= n; ++j)
			{
				part[j] += part[j-i];
				part[j] %= mod;
			}

			debug("");
		}

		int ans = 0;

		for(int i = 1; i <= n; ++i)
		{
			ans += part[i];
			ans %= mod;
		}

		cout << ans << endl;
	}
	else if(k==2)
	{
		int ans = 0;

		dwa[0] = 1;

		for(int step = 1; step*(step+1)/2 <= n; ++step)
		{
			int x = step*(step+1)/2;

			for(int i = x; i <= n; ++i)
			{
				dwa[i] += dwa[i-x];
				dwa[i] %= mod;
			}
		}

		for(int i = 1; i <= n; ++i)
		{
			ans += dwa[i];
			ans %= mod;     
		}

		cout << ans << endl;	
	}
	else
	{
		maxSum = 1;

		while((maxSum+1)*(maxSum+1)<=2*n)
			++maxSum;

		vec.pb(1);
		rec();

		cout << cnt << endl;
	}
}