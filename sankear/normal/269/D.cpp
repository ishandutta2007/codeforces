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
#include <complex>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define next _next
#define prev _prev
#define rank _rank
#define link _link

typedef long long ll;
typedef long long llong;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef complex <double> tc;

const int inf = int(2e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));

struct ts{
	int x, num, t;
};

int maxv;
bool bad[100100];
int h[100100], l[100100], deg[100100], r[100100], num[100100], d[100100];
ts s[200200];
vi v[100100], g[100100];
int rmq[280280];

bool operator < (const ts &a, const ts &b){
	if(a.x != b.x){
		return a.x < b.x;
	}
	return a.t > b.t;
}

inline bool check(int a, int b){
	return max(l[a], l[b]) < min(r[a], r[b]);
}

inline bool cmpl(int a, int b){
	return l[a] < l[b];
}

inline bool cmpr(int a, int b){
	return r[a] < r[b];
}

inline bool cmph(int a, int b){
	return h[a] > h[b];
}

inline int get(int l, int r){
	int res = -inf;
	l += maxv;
	r += maxv;
	while(l <= r){
		res = max(res, rmq[l]);
		l = (l + 1) / 2;
		res = max(res, rmq[r]);
		r = (r - 1) / 2;
	}
	return res;
}

inline int get_val(int a, int b){
	return min(r[a], r[b]) - max(l[a], l[b]);
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	int n, t;
	scanf("%d %d", &n, &t);
	for(int i = 0; i < n; i++){
		scanf("%d %d %d", &h[i], &l[i], &r[i]);
	}
	int m = 0;
	for(int i = 0; i < n; i++){
		s[m].x = l[i];
		s[m].num = i;
		s[m++].t = 1;
		s[m].x = r[i];
		s[m].num = i;
		s[m++].t = 2;
	}
	sort(s, s + m);
	set <pii> S;
	for(int i = 0; i < m; i++){
		if(s[i].t == 1){
			set <pii> :: iterator it = S.upper_bound(mp(h[s[i].num], -inf));
			if(it != S.end()){
				if(check(it->sc, s[i].num)){
					v[it->sc].pb(s[i].num);
				}
			}
			it = S.lower_bound(mp(h[s[i].num], -inf));
			if(it != S.begin()){
				it--;
				if(check(s[i].num, it->sc)){
					v[s[i].num].pb(it->sc);
				}
			}
			S.insert(mp(h[s[i].num], s[i].num));
		}
		else{
			S.erase(mp(h[s[i].num], s[i].num));
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < sz(v[i]); j++){
			bad[v[i][j]] = false;
		}
		maxv = 1;
		while(maxv < sz(v[i])){
			maxv *= 2;
		}
		sort(v[i].begin(), v[i].end(), cmpl);
		for(int j = 0; j < sz(v[i]); j++){
			rmq[j + maxv] = h[v[i][j]];
		}
		for(int j = sz(v[i]); j < maxv; j++){
			rmq[j + maxv] = -inf;
		}
		for(int j = maxv - 1; j > 0; j--){
			rmq[j] = max(rmq[j * 2], rmq[j * 2 + 1]);
		}
		for(int j = sz(v[i]) - 1; j >= 0; j--){
			int gl = -1, L = 0, R = sz(v[i]) - 1;
			while(L <= R){
				int mid = (L + R) / 2;
				if(l[v[i][mid]] >= l[v[i][j]]){
					gl = mid;
					R = mid - 1;
				}
				else{
					L = mid + 1;
				}
			}
			int gr = -1;
			L = gl;
			R = sz(v[i]) - 1;
			while(L <= R){
				int mid = (L + R) / 2;
				if(l[v[i][mid]] < r[v[i][j]]){
					gr = mid;
					L = mid + 1;
				}
				else{
					R = mid - 1;
				}
			}
			if(max(get(gl, j - 1), get(j + 1, gr)) > h[v[i][j]]){
				bad[v[i][j]] = true;
			}
		}
		sort(v[i].begin(), v[i].end(), cmpr);
		for(int j = 0; j < sz(v[i]); j++){
			rmq[j + maxv] = h[v[i][j]];
		}
		for(int j = sz(v[i]); j < maxv; j++){
			rmq[j + maxv] = -inf;
		}
		for(int j = maxv - 1; j > 0; j--){
			rmq[j] = max(rmq[j * 2], rmq[j * 2 + 1]);
		}
		for(int j = 0; j < sz(v[i]); j++){
			int gl = -1, L = 0, R = sz(v[i]) - 1;
			while(L <= R){
				int mid = (L + R) / 2;
				if(r[v[i][mid]] > l[v[i][j]]){
					gl = mid;
					R = mid - 1;
				}
				else{
					L = mid + 1;
				}
			}
			int gr = -1;
			L = gl;
			R = sz(v[i]) - 1;
			while(L <= R){
				int mid = (L + R) / 2;
				if(r[v[i][mid]] <= r[v[i][j]]){
					gr = mid;
					L = mid + 1;
				}
				else{
					R = mid - 1;
				}
			}
			if(max(get(gl, j - 1), get(j + 1, gr)) > h[v[i][j]]){
				bad[v[i][j]] = true;
			}
			for(int j = 0; j < sz(v[i]); j++){
				if(!bad[v[i][j]]){
					g[i].pb(v[i][j]);
					deg[v[i][j]]++;
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		num[i] = i;
	}
	sort(num, num + n, cmph);
	for(int i = 0; i < n; i++){
		d[i] = -inf;
	}
	for(int i = 0; i < n; i++){
		if(deg[num[i]] == 0){
			d[num[i]] = max(d[num[i]], r[num[i]] - l[num[i]]);
		}
		for(int j = 0; j < sz(g[num[i]]); j++){
			d[g[num[i]][j]] = max(d[g[num[i]][j]], min(d[num[i]], get_val(num[i], g[num[i]][j])));
		}
	}
	int ans = -inf;
	for(int i = 0; i < n; i++){
		if(sz(g[num[i]]) == 0){
			ans = max(ans, d[num[i]]);
		}
	}
	printf("%d\n", ans);
	return 0;
}