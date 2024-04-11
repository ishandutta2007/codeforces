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
#include <stack>
#include <cassert>
#include <list>
//#include <unordered_set>
using namespace std;
typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define mp make_pair
#define pb push_back
#define all(s) s.begin(), s.end()
void solve();

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    clock_t start = clock();
#else
	
    //freopen("taxi.in", "r", stdin);
    //freopen("taxi.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();

#ifdef DEBUG
    cout << "\n\n\nTime:" << ((clock() - start) / 1.0 / CLOCKS_PER_SEC);
#endif
    return 0;
}

map<pi, int> l;
bool bad[101010];
int parent[101010];
vi g[101010];

int maxExeptParent[101010];
int whMax[101010];
int secMax[101010];


void dfs(int v, int p) {
	parent[v] = p;
	int& mx = maxExeptParent[v];
	mx = -1;
	secMax[v] = -1;
	whMax[v] = -1;
	
	for(int to: g[v]) {
		if(to == p)
			continue;
		dfs(to, v);
		if(mx < maxExeptParent[to]) {
			secMax[v] = mx;
			mx = maxExeptParent[to];
			whMax[v] = to;
		}
		else if(secMax[v] < maxExeptParent[to]) {
			secMax[v] = maxExeptParent[to];
		}
	}
	if(mx != -1 || bad[v])
		++mx;
	
	if(secMax[v] != -1 || bad[v])
		++secMax[v];
	
}

int exceptDown(int v, int e) {
	if(whMax[v] == e)
		return secMax[v];
	return maxExeptParent[v];
}

map<pi, int> ee;

int except(int v, int e) {
	if(v == -1)
		return -1;
	pi key = mp(v, e);
	if(ee.find(key) != ee.end())
		return ee[key];
	
	int par = except(parent[v], v);
//	cerr << "exc" << v << ' ' << e << ' '<< max(exceptDown(v, e), par == -1 ? -1 : par + 1) << endl;
	return ee[key] = max(exceptDown(v, e), par == -1 ? -1 : par + 1);
}


void solve(){
	int n, m , d;
	cin >> n >> m >> d;
	for(int i = 0; i < m; ++i) {
		int a;
		cin >> a ;
		--a;
		bad[a] = true;
	}
	for(int i =1 ; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	dfs(0, -1);
	
	int ans = 0;
	//cerr << maxExeptParent[0] << ' ' << secMax[0] << ' ' << whMax[0] << endl;
	if(maxExeptParent[0] <= d) {
		//cerr << "e.g" << 0 << endl;
		++ans;
	}
	
	for(int i = 1; i < n; ++i) {
		int t = except(parent[i], i);
		int l = max(maxExeptParent[i], t == -1 ? -1 : t + 1);
		if(l <= d) {
		//	cerr << "e.g" << i << endl;
			//cerr << t << ' '<< l << endl;
			++ans;
		}
	}
	
	cout << ans;
}