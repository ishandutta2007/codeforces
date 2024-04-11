#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 411111

#define TASK "1"

using namespace std;

int n;



vector<long long> solve(vector<long long> a) {
	if (a.size() == 0) return a;
	long long g = a[0];
	for (int i = 1; i < a.size(); i++) g = __gcd(g, a[i]);

	vector<long long> e, o;
	for (int i = 0; i < a.size(); i++) if (a[i] / g % 2 == 0) e.pb(a[i]); else o.pb(a[i]);


	vector<long long> t = solve(e);

	if (e.size() < o.size() + t.size()) return e;

	for (auto x : t) o.pb(x);
	return o;
	
}


int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i <n; i++) cin >> a[i];

	auto e = solve(a);

	cout << e.size() << endl;
	for (long long x : e) cout << x << " ";

	return 0;
}