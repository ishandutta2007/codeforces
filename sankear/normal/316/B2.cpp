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
const int N = 1000;

int sz;
bool can[N + 100], used[N + 100];
int go[N + 100];
vi g[N + 100];

void dfs(int a){
	sz++;
	used[a] = true;
	for(int i = 0; i < sz(g[a]); i++){
		if(!used[g[a][i]]){
			dfs(g[a][i]);
		}
	}
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, x;
	scanf("%d %d", &n, &x);
	x--;
	for(int i = 0; i < n; i++){
		scanf("%d", &go[i]);
		go[i]--;
		if(go[i] != -1){
			g[i].pb(go[i]);
			g[go[i]].pb(i);
		}
	}
	int num = 1, cur = x;
	while(go[cur] != -1){
		num++;
		cur = go[cur];
	}
	dfs(x);
	can[0] = true;
	for(int i = 0; i < n; i++){
		if(!used[i]){
			sz = 0;
			dfs(i);
			for(int j = n; j >= sz; j--){
				can[j] |= can[j - sz];
			}
		}
	}
	for(int i = 0; i + num <= n; i++){
		if(can[i]){
			printf("%d\n", i + num);
		}
	}
	return 0;
}