#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define ll long long
#define VI vector<int>
#define VLL vector<ll>
#define PII pair<int, int>
#define VPII vector<PII>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
const int inf = 1e9L+7;
const ll INF = 1e18L+7;

#define Sim template <class n
Sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{ return p << "<" << x.first << ", " << x.second << ">"; }
Sim> auto operator << (ostream &p, n y) -> 
typename enable_if <!is_same<n, string>::value, decltype(y.begin(), p)>::type 
{ int o = 0; p << "{"; for(auto c: y) { if(o++) p << ", "; p << c; } return p << "}"; }
void dor() { cerr << endl; }
Sim, class...s> void dor(n p, s...y) { cerr << p; dor(y...); }
Sim, class s> void mini(n &p, s y) { if(p > y) p = y; }
Sim, class s> void maxi(n &p, s y) { if(p < y) p = y; }
#ifdef DEB
#define debug(...) dor(__FUNCTION__, ":", __LINE__, ": ", __VA_ARGS__)
#else
#define debug(...)
#endif 

#define I(x) #x " = ", (x), " "
#define A(a, i) #a "[" #i " = ", i, "] = ", a[i], " "

#define y1 ababbabab
#define int ll
#define double long double

int a, b, c, x1, y1, x2, y2;

pair<double, double> go(int x, int y, int dim)
{
	if(dim==0)
		return mp((double)(-c-b*y)/a, y);
	else
		return mp(x, (double)(-c-a*x)/b);
}

double dist(pair<double, double> a, pair<double, double> b)
{
	return sqrt((a.st-b.st)*(a.st-b.st)+(a.nd-b.nd)*(a.nd-b.nd));
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cout << fixed << setprecision(15);

	cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;

	double ans = abs(x1-x2)+abs(y1-y2);

	if(a==0 || b==0)
	{
		cout << ans << endl;
		return 0;
	}

	auto X = go(x2, y2, 0);

	for(int i = 0; i < 2; ++i)
	{
		for(int j = 0; j < 2; ++j)
		{
			pair<double, double> A = go(x1, y1, i);
			pair<double, double> B = go(x2, y2, j);

			ans = min(ans, dist(mp(x1, y1), A) + dist(A, B) + dist(B, mp(x2, y2)));
		}
	}

	cout << ans << endl;
}