#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <queue>
#include <cassert>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define forit(it,v) for(typeof((v).begin()) it = v.begin() ; it != (v).end() ; ++it)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;


#define TASK "a"
int n;
vector<pair<vi, int> > ls[1000000];
vector<int> ost[1000000];
vector<pair<int, int> > ob[1000000];

int was[1000000];
int gd[1000000];

ll f[1000000];
ll d[1000000];


const ll inf = 314000000;
void calc_max(int x) {	
	was[x] = 1;
	for (int i = 0; i < sz(ls[x]); i++) {
		ll sum = ls[x][i].y;
		bool can = true;
		for (int j = 0; j < sz(ls[x][i].x); j++) {
			int e = (ls[x][i].x)[j];
			if (gd[e] == 0) {
				can = false;
			}
		}
		if (!can) continue;
		for (int j = 0; j < sz(ls[x][i].x); j++) {
			int e = (ls[x][i].x)[j];
			if (was[e] == 0) {
				calc_max(e);				
			} else 
			if (was[e] == 1) {
				f[x] = -2;				
				was[x] = 2;
				return;
			}
			if (f[e] == -2) {
				f[x] = -2;
				was[x] = 2;
				return;
			} else {
				sum += f[e];
			}
		}
		f[x] = max(f[x], min(sum, inf)); 
	}
	was[x] = 2;
}
void calc_min(int x) {	
	was[x] = 1;
	for (int i = 0; i < sz(ls[x]); i++) {
		ll sum = ls[x][i].y;
		bool can = true;
		for (int j = 0; j < sz(ls[x][i].x); j++) {
			int e = (ls[x][i].x)[j];
			if (gd[e] == 0) {
				can = false;
			}
		}
		if (!can) continue;
		for (int j = 0; j < sz(ls[x][i].x); j++) {
			int e = (ls[x][i].x)[j];
			if (was[e] == 0) {
				calc_min(e);				
			}
			sum += d[e];
		}
		d[x] = min(d[x], min(sum, inf)); 
	}
	was[x] = 2;
}
int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    int m;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
    	int tk, k;
    	scanf("%d %d", &tk, &k);
    	tk--;
    	int c = 0;
    	vi v;
    	for (int j = 0; j < k; j++) {
    		int x;
    		scanf("%d", &x);
    		if (x == -1) {
    			c++;
    		} else {
    			v.pb(x - 1);
    			ob[x - 1].pb(mp(tk, sz(ls[tk])));
    		}
    	}
    	ls[tk].pb(mp(v, c));
    	ost[tk].pb(sz(v));
    }
    for (int i = 0; i < n; i++) {
    	gd[i] = 0;
    }
    for (int i = 0; i < n; i++) {
    	d[i] = inf;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
    	bool good = false;
    	for (int j = 0; j < sz(ls[i]); j++) {
    		if (sz(ls[i][j].x) == 0) {
    			good = true;
    			d[i] = min(d[i], (ll)ls[i][j].y);
    		}
    	}
    	if (good) {
    		q.push(i);
	    	gd[i] = 1;
    	}
    }
    while (!q.empty()) {
    	int v = q.front();
    	q.pop();
    	for (int i = 0; i < sz(ob[v]); i++) {
    		ost[ob[v][i].x][ob[v][i].y]--;
    		if (ost[ob[v][i].x][ob[v][i].y] == 0 && gd[ob[v][i].x] == 0) {
    			gd[ob[v][i].x] = 1;
    			q.push(ob[v][i].x);
    		}
    	}
    }        
    for (int i = 0; i < n; i++) {
    	was[i] = 0;
    }
    for (int i = 0; i < n; i++) {
    	if (gd[i] == 0) {
    		continue;
    	}
    	if (was[i] == 0) {
    		calc_min(i);
    	}
    }
    for (int i = 0; i < n; i++) {
    	was[i] = 0;
    	f[i] = -3;
    }
    for (int i = 0; i < n; i++) {
    	if (gd[i] == 0) {
    		printf("-1 -1\n");
    		continue;
    	}
    	if (was[i] == 0) {
    		calc_max(i);
    	}
    	printf("%I64d %I64d\n", d[i], f[i]);
    }
    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}