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
typedef double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = (int)1e9;
const ld eps = 1e-9;


#define TASK "a"
char S[1000000];
char t[1000000];
char* ff;
char* s[1000000];
int p[1000000];
int bc[1000000];
int cnt[1000000];
int b[301000][26];
int n, m;
int ans = 0;
vi g[1000000];
int kv = 1;
void dfs(int v, int tk) {
	if (v != 0)
	for (int i = 0; s[v][i]; i++) {
		int c = s[v][i] - 'a';
		if (b[tk][c] == 0) {
			b[tk][c] = ++kv;
		}
		tk = b[tk][c];
		cnt[tk]++;
	}
	for (int i = 0; i < sz(g[v]); i++) {
		dfs(g[v][i], tk);
	}
}
inline int go(int k, char c) {
	while (t[k] != c && k != 0) {
		k = p[k - 1];
	}
	if (t[k] == c) {
		k++;
	}
	return k;
}
void dfs2(int tk, int k) {
	if (k == m) {
		ans += cnt[tk];
	}
	for (int i = 0; i < 26; i++) {
		if (b[tk][i] != 0) {
			dfs2(b[tk][i], go(k, i + 'a'));
		}
	}
}
int main()
{
	#ifdef home
		assert(freopen(TASK".in", "r", stdin));
		assert(freopen(TASK".out", "w", stdout));
	#endif
	scanf("%d", &n);
	ff = S;
	for (int i = 1; i < n; i++) {
		scanf("%d %s", &bc[i], ff);
		bc[i]--;
		g[bc[i]].pb(i);
		s[i] = ff;
		ff += strlen(ff) + 1;
	}
	scanf("%s", t);
	m = strlen(t);
	p[0] = 0;
	for (int i = 1; i < m; i++) {
		p[i] = p[i - 1];
		while (t[p[i]] != t[i] && p[i] != 0) {
			p[i] = p[p[i] - 1];
		}
		if (t[p[i]] == t[i]) {
			p[i]++;
		}
	}
	dfs(0, 1);
	dfs2(1, 0);
	cout<<ans<<endl;
	#ifdef home
		eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
	#endif
	return 0;
}