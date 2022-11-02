#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <deque>
#include <string>

#include <algorithm>
#include <numeric>

#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

#define pb push_back
#define pbk pop_back
#define mp make_pair
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define foreach(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define len(a) ((int) (a).size())

#ifdef CUTEBMAING
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

using namespace std;

typedef long long int64;
typedef long double ld;
typedef unsigned long long lint;

const int inf = (1 << 30) - 1;
const int64 linf = (1ll << 62) - 1;
const int N = 1e6 + 100;

int n, m;
set<int> g[N];
vector<int> comp;
bool used[N];

void dfs(int v) {
	if (used[v]) {
		return ;
	}
	used[v] = true;
	comp.pb(v);
	for (int to : g[v]) {
		dfs(to);
	}
}

int main() {
#ifdef XCODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
    	int a, b; scanf("%d%d", &a, &b), a--, b--;
    	g[a].insert(b);
    	g[b].insert(a);
    }
    for (int i = 0; i < n; i++) {
    	if (!used[i]) {
    		comp.clear();
    		dfs(i);
    		for (int j = 0; j < len(comp); j++) {
    			for (int z = j + 1; z < len(comp); z++) {
    				if (g[comp[j]].count(comp[z]) == 0) {
    					puts("NO");
    					return 0;
    				}
    			}
    		}
    	}
    }
    puts("YES");
    return 0;
}