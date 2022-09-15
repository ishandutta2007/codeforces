#include <iostream> 
#include <cstdio> 
#include <set> 
#include <map> 
#include <vector> 
#include <queue> 
#include <stack> 
#include <cmath> 
#include <algorithm> 
#include <cstring> 
#include <bitset> 
#include <ctime> 
#include <sstream>
#include <stack> 
#include <cassert> 
#include <list> 
//#include <unordered_set> 
using namespace std;
typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define mp make_pair 
#define pb push_back 
#define all(s) s.begin(), s.end() 
void solve();

#define NAME "heavy"
int main() {
#ifdef DEBUG 
	//cerr << NAME << endl;
	freopen("input", "r", stdin);
	//freopen("output", "w", stdout); 
	clock_t start = clock();
#else 
	//freopen(NAME".in", "r", stdin); 
	//freopen(NAME".out", "w", stdout); 
#endif 
	ios_base::sync_with_stdio(false);
	cout << fixed;
	cout.precision(2);
	int t = 1;
	//cin >> t; 
	while (t--)
		solve();

#ifdef DEBUG 
	cout << "\n\n\nTime:" << ((clock() - start) / 1.0 / CLOCKS_PER_SEC);
#endif 
	return 0;
	
}

vector<int> g[202020];
int lev[202020];
int in[202020];
int out[202020];
int timer = 0;
void dfs(int v, int p, int l){
	lev[v] = l;
	in[v] = timer++;
	for(int to:g[v])
		if(to!=p)
			dfs(to, v, l + 1);
	out[v] = timer;
}
const int shift = 1 << 18;
int rmq[1<<19];

int get(int v) {
	if(!v)
		return 0;
	return rmq[v] + get(v / 2);
}

void upd(int l, int r, int d) {
	if(l >= r)
		return;
	if(l % 2) {
		rmq[l] += d;
		return upd(l + 1, r, d);
	}
	if(r % 2) {
		rmq[r - 1] += d;
		return upd(l, r - 1, d);
	}
	upd(l / 2, r / 2, d);
}
void solve() {
	int n,m;
	cin >> n >> m;
	vector<int> initial(n);
	for(int& x: initial) {
		cin >> x;
	}
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		//cerr << a << ' ' << b << endl;
		--a, --b;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0, -1, 0);
	for(int i = 0; i < n; ++i) {
		if(lev[i] % 2) 
			initial[i] = -initial[i];
		rmq[in[i] + shift] = initial[i];
	}
	for(int i = 0; i < m; ++i) {
		int type;
		cin >> type;
		if(type == 2) {
			int x;
			cin >> x;
			--x;
			int r = get(in[x] + shift);
			if(lev[x] % 2)
				r = -r;
			cout << r << '\n';
		}
		else {
			int v, d;
			cin >> v >> d;
			--v;
			if(lev[v] % 2)
				d = -d;
			upd(in[v] + shift, out[v] +  shift, d);
		}
		
	}
}