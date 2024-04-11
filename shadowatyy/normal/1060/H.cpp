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

#define int ll

int d, p, curr;

int gdzie[1<<10];

int t[5007];

int fpow(int a, int b)
{
	int res = 1;

	while(b)
	{
		if(b&1)
			res = res*a%p;

		a = a*a%p;
		b /= 2;
	}

	return res;
}

void add(int a, int b, int c)
{
	cout << "+ " << a << " " << b << " " << c << endl;
	//t[c] = t[a] + t[b];
	//t[c] %= p;
}

void raise(int a, int b)
{
	cout << "^ " << a << " " << b << endl;

	//t[b] = fpow(t[a], d);
}

void mult(int ind, int chce)
{
	if(chce==1)
		return;

	add(ind, gdzie[0], 4999);
	mult(ind, chce/2);
	add(ind, ind, ind);

	if(chce%2)
		add(ind, 4999, ind);	
}

void make_zero(int ind, int chce)
{
	if(chce==1)
		return;

	make_zero(ind, chce/2);
	add(ind, ind, ind);

	if(chce%2)
		add(ind, 5000, ind);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> d >> p;

	curr = d;
	gdzie[0] = ++curr;
	make_zero(gdzie[0], p);

	for(int i = 1; i < 1<<d; ++i)
	{
		gdzie[i] = ++curr;
		int bit = 31-__builtin_clz(i&-i);
		add(gdzie[i - (i&-i)], bit+1, gdzie[i]);
	}

	debug(t[gdzie[(1<<d)-1]]);

	for(int i = 0; i < 1<<d; ++i)
	{
		raise(gdzie[i], gdzie[i]);
	}

	//debug(t[gdzie[(1<<d)-1]]);
	//debug(fpow(2, d));

	int sum_np = ++curr;
	add(gdzie[0], gdzie[0], sum_np);

	int ans = ++curr;
	add(gdzie[0], gdzie[0], ans);

	for(int i = 0; i < 1<<d; ++i)
	{
		if(__builtin_popcount(i)%2!=d%2)
			add(sum_np, gdzie[i], sum_np);
		else
			add(ans, gdzie[i], ans);
	}

	mult(sum_np, p-1);
	add(ans, sum_np, ans);

	for(int i = 2; i <= d; ++i)
	{
		debug(fpow(i, p-2));
		mult(ans, fpow(i, p-2));
	}

	cout << "f " << ans << endl;

	for(int i = 1; i <= curr; ++i)
	{
		cerr << i << " " << t[i] << endl;
	}

	cerr << t[ans] << endl;
}