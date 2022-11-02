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

int step, k, maxv, l, w, all, max_size, ver;
ll ans;
int first[100100], len[100100], cost[100100], prev[100100], lst[100100], sz[100100], used[100100];
pii p[100100];
int go[200200], cnt[200200], next[200200];
vector <pii> pos[100100];
vi T[280280], F[280280];

inline void add(int a, int b, int c){
	go[++k] = b;
	cnt[k] = c;
	next[k] = first[a];
	first[a] = k;
}

void dfs1(int v){
	used[v] = step;
	sz[v] = 1;
	for(int i = first[v]; i > 0; i = next[i]){
		if(used[go[i]] != step){
			dfs1(go[i]);
			sz[v] += sz[go[i]];
		}
	}
}

void dfs2(int v){
	used[v] = step;
	int size = all - sz[v];
	for(int i = first[v]; i > 0; i = next[i]){
		if(used[go[i]] != step){
			dfs2(go[i]);
			size = max(size, sz[go[i]]);
		}
	}
	if(size < max_size){
		max_size = size;
		ver = v;
	}
}

void dfs3(int v, int pv = -1){
	used[v] = step;
	prev[v] = pv;
	sz[v] = 1;
	if(prev[v] != -1){
		lst[k] = v;
		p[k++] = mp(len[v], v);
	}
	for(int i = first[v]; i > 0; i = next[i]){
		if(used[go[i]] != step){
			len[go[i]] = len[v] + 1;
			cost[go[i]] = cost[v] + cnt[i];
			dfs3(go[i], (pv == -1 ? go[i] : pv));
			sz[v] += sz[go[i]];
		}
	}
}

inline bool cmp(int a, int b){
	return prev[a] < prev[b];
}

inline void add(vi &f, int pos){
	while(pos < sz(f)){
		f[pos]++;
		pos = (pos | (pos + 1));
	}
}

inline int get(vi &f, int pos){
	int res = 0;
	while(pos >= 0){
		res += f[pos];
		pos = (pos & (pos + 1)) - 1;
	}
	return res;
}

inline int find(int val){
	int res = -1, l = 0, r = k - 1;
	while(l <= r){
		int mid = (l + r) / 2;
		if(p[mid].fs <= val){
			res = mid;
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	return res;
}

inline int get(int l, int r, int val){
	int res = 0;
	l += maxv;
	r += maxv;
	while(l <= r){
		if(l % 2 != 0){
			int need = -1, gl = 0, gr = sz(T[l]) - 1;
			while(gl <= gr){
				int mid = (gl + gr) / 2;
				if(cost[T[l][mid]] <= val){
					need = mid;
					gl = mid + 1;
				}
				else{
					gr = mid - 1;
				}
			}
			res += get(F[l], need);
		}
		l = (l + 1) / 2;
		if(r % 2 == 0){
			int need = -1, gl = 0, gr = sz(T[r]) - 1;
			while(gl <= gr){
				int mid = (gl + gr) / 2;
				if(cost[T[r][mid]] <= val){
					need = mid;
					gl = mid + 1;
				}
				else{
					gr = mid - 1;
				}
			}
			res += get(F[r], need);
		}
		r = (r - 1) / 2;
	}
	return res;
}

inline void solve(int v){
	all = sz[v];
	max_size = inf;
	step++;
	dfs2(v);
	len[ver] = cost[ver] = 0;
	k = 0;
	step++;
	dfs3(ver);
	sort(p, p + k);
	maxv = 1;
	while(maxv < k){
		maxv *= 2;
	}
	for(int i = 1; i < 2 * maxv; i++){
		T[i].clear();
	}
	for(int i = 0; i < k; i++){
		T[i + maxv].pb(p[i].sc);
	}
	for(int i = maxv - 1; i > 0; i--){
		int j = 0, z = 0;
		while(j < sz(T[i * 2]) && z < sz(T[i * 2 + 1])){
			if(cost[T[i * 2][j]] < cost[T[i * 2 + 1][z]]){
				T[i].pb(T[i * 2][j++]);
			}
			else{
				T[i].pb(T[i * 2 + 1][z++]);
			}
		}
		while(j < sz(T[i * 2])){
			T[i].pb(T[i * 2][j++]);
		}
		while(z < sz(T[i * 2 + 1])){
			T[i].pb(T[i * 2 + 1][z++]);
		}
	}
	for(int i = 1; i < 2 * maxv; i++){
		F[i].resize(sz(T[i]));
		for(int j = 0; j < sz(F[i]); j++){
			F[i][j] = 0;
		}
	}
	for(int i = 0; i < k; i++){
		pos[lst[i]].clear();
	}
	for(int i = 1; i < 2 * maxv; i++){
		for(int j = 0; j < sz(T[i]); j++){
			pos[T[i][j]].pb(mp(i, j));
		}
	}
	sort(lst, lst + k, cmp);
	int i = 0;
	while(i < k){
		int j = i;
		while(j + 1 < k && prev[lst[i]] == prev[lst[j + 1]]){
			j++;
		}
		for(int z = i; z <= j; z++){
			if(len[lst[z]] <= l && cost[lst[z]] <= w){
				ans++;
			}
			int pos = find(l - len[lst[z]]);
			ans += get(0, pos, w - cost[lst[z]]);
		}
		for(int z = i; z <= j; z++){
			for(int h = 0; h < sz(pos[lst[z]]); h++){
				add(F[pos[lst[z]][h].fs], pos[lst[z]][h].sc);
			}
		}
		i = j + 1;
	}
	for(int i = first[ver]; i > 0; i = next[i]){
		int last = -1;
		for(int j = first[go[i]]; j > 0; j = next[j]){
			if(go[j] == ver){
				if(last == -1){
					first[go[i]] = next[j];
				}
				else{
					next[last] = next[j];
				}
				break;
			}
			last = j;
		}
	}
	for(int i = first[ver]; i > 0; i = next[i]){
		solve(go[i]);
	}
}

inline void gen(){
	freopen("input.txt", "w", stdout);
	int n = int(1e5), l = n, w = int(1e9);
	cout << n << " " << l << " " << w << endl;
	for(int i = 1; i < n; i++){
		int p = rand() % i;
		cout << i << " " << rand() % (int(1e4) + 1) << endl;
	}
	exit(0);
}

int main(){
	//gen();
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d %d %d", &n, &l, &w);
	k = 0;
	for(int i = 0; i < n - 1; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		add(a, i + 1, b);
		add(i + 1, a, b);
	}
	step = 1;
	dfs1(0);
	solve(0);
	printf(LLD"\n", ans);
	return 0;
}