#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define LLD "%lld"
#else
#define eprintf(...) 42
#define LLD "%I64d"
#endif
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash

typedef long long ll;
typedef long long llong;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef complex <double> tc;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));

ll ans;
bool used[100100];
ll a[100100], b[100100], c[100100];
vi v[100100];

void dfs(int ver){
	used[ver] = true;
	b[ver] = c[ver] = 0;
	for(int i = 0; i < sz(v[ver]); i++){
		if(!used[v[ver][i]]){
			dfs(v[ver][i]);
			b[ver] = min(b[ver], b[v[ver][i]]);
			c[ver] = max(c[ver], c[v[ver][i]]);
		}
	}
	a[ver] += b[ver] + c[ver];
	if(ver == 0){
		ans += -b[ver] + c[ver];
	}
	if(a[ver] < 0){
		if(ver == 0){
			ans -= a[ver];
		}
		c[ver] -= a[ver];
	}
	else{
		if(a[ver] > 0){
			if(ver == 0){
				ans += a[ver];
			}
			b[ver] -= a[ver];
		}
	}
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	for(int i = 0; i < n; i++){
		scanf(LLD, &a[i]);
	}
	ans = 0;
	dfs(0);
	printf(LLD"\n", ans);
	return 0;
}