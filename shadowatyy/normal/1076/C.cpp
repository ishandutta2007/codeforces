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

#define db long double
#define eps 1e-8

int t;

db d;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> t;

	cout << fixed << setprecision(15);

	while(t--)
	{
		cin >> d;

		db a = -1;
		db b = d;
		db c = -d;
		db del = b*b - 4*a*c;

		if(del<-eps)
			cout << "N" << endl;
		else
		{
			del = sqrt(del);

			if((-b+del)/(2*a)>-eps && (-b-del)/(2*a)>-eps)
				cout << "Y " << (-b+del)/(2*a) << " " << (-b-del)/(2*a) << endl;
			else
				cout << "N" << endl;
		}
	}
}