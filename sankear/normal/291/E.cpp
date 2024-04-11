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
const int X1 = 4243;
const int X2 = 10007;
const int MOD1 = int(1e9) + 7;
const int MOD2 = 42424243;
const int steps = 18;

struct hash{
	int h1, h2;
	
	hash(){}
	
	hash(int _h1, int _h2){
		h1 = _h1;
		h2 = _h2;
	}
	
};

hash operator + (const hash &a, const hash &b){
	hash c(a.h1 + b.h1, a.h2 + b.h2);
	if(c.h1 >= MOD1){
		c.h1 -= MOD1;
	}
	if(c.h2 >= MOD2){
		c.h2 -= MOD2;
	}
	return c;
}

hash operator * (const hash &a, const hash &b){
	return hash((ll(a.h1) * b.h1) % MOD1, (ll(a.h2) * b.h2) % MOD2);
}

bool operator == (const hash &a, const hash &b){
	return a.h1 == b.h1 && a.h2 == b.h2;
}

int sz;
vi v[100100];
int len[100100];
char *s[100100];
char buf[300300];
vector <pair <int, char> > g[400400];
hash P[400400];
int p[steps + 1][400400];
hash h[steps + 1][400400];

void build(int a){
	for(int i = 0; i < sz(v[a]); i++){
		int cur = a;
		for(int j = 0; j < len[v[a][i]] - 1; j++){
			g[cur].pb(mp(sz, s[v[a][i]][j]));
			cur = sz++;
		}
		g[cur].pb(mp(v[a][i], s[v[a][i]][len[v[a][i]] - 1]));
		build(v[a][i]);
	}
}

void dfs(int a){
	for(int i = 0; i < sz(g[a]); i++){
		p[0][g[a][i].fs] = a;
		h[0][g[a][i].fs] = hash(g[a][i].sc, g[a][i].sc);
		dfs(g[a][i].fs);
	}
}

inline bool check(int v, int len, hash need){
	int cur = 0;
	hash cur_hash(0, 0);
	for(int i = steps; i >= 0; i--){
		if(p[i][v] != -1 && cur + (1 << i) <= len){
			cur_hash = cur_hash + h[i][v] * P[cur];
			cur += (1 << i);
			v = p[i][v];
		}
	}
	if(cur < len){
		return false;
	}
	return cur_hash == need;
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		int p;
		scanf("%d %s", &p, buf);
		p--;
		v[p].pb(i);
		len[i] = strlen(buf);
		s[i] = new char[len[i] + 1];
		strcpy(s[i], buf);
	}
	sz = n;
	build(0);
	for(int i = 0; i <= steps; i++){
		for(int j = 0; j < sz; j++){
			p[i][j] = -1;
		}
	}
	dfs(0);
	P[0] = hash(1, 1);
	P[1] = hash(X1, X2);
	for(int i = 2; i <= sz; i++){
		P[i] = P[i - 1] * P[1];
	}
	for(int i = 1; i <= steps; i++){
		for(int j = 0; j < sz; j++){
			if(p[i - 1][j] == -1){
				continue;
			}
			p[i][j] = p[i - 1][p[i - 1][j]];
			h[i][j] = h[i - 1][j] + h[i - 1][p[i - 1][j]] * P[(1 << (i - 1))];
		}
	}
	scanf("%s", buf);
	int m = strlen(buf);
	hash need(0, 0);
	for(int i = 0; i < m; i++){
		need = need * P[1] + hash(buf[i], buf[i]);
	}
	int ans = 0;
	for(int i = 0; i < sz; i++){
		if(check(i, m, need)){
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}