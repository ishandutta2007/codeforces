#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
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
#define hash _hash
#ifdef LOCAL
#define LLD "%I64d"
#else
#define LLD "%I64d"
#endif
 
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;
 
const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(1e5) + 100;
const int RMQ = 280280;

struct query{
	int num, l, t, lft, rgh;
	query(){}
	query(int _num, int _l, int _t, int _lft, int _rgh){
		num = _num;
		l = _l;
		t = _t;
		lft = _lft;
		rgh = _rgh;
	}
};

struct tr{
	int val, cnt, add, l, r;
};

int sz, maxv;
bool used[N];
int lft[N], rgh[N], lst[N], ans[N], A[N], B[N];
vi v[N];
vector <query> q1[N], q2[N];
tr rmq[RMQ];

void dfs(int a){
	used[a] = true;
	lft[a] = sz;
	lst[sz++] = a;
	for(int i = 0; i < sz(v[a]); i++){
		if(!used[v[a][i]]){
			dfs(v[a][i]);
		}
	}
	rgh[a] = sz - 1;
}

inline void calc(int v){
	rmq[v].val = rmq[v * 2].val;
	rmq[v].cnt = rmq[v * 2].cnt;
	if(rmq[v * 2 + 1].val < rmq[v].val){
		rmq[v].val = rmq[v * 2 + 1].val;
		rmq[v].cnt = rmq[v * 2 + 1].cnt;
	}
	else{
		if(rmq[v * 2 + 1].val == rmq[v].val){
			rmq[v].cnt += rmq[v * 2 + 1].cnt;
		}
	}
}

inline void push(int v){
	rmq[v].val += rmq[v].add;
	if(v < maxv){
		rmq[v * 2].add += rmq[v].add;
		rmq[v * 2 + 1].add += rmq[v].add;
	}
	rmq[v].add = 0;
}

void update(int v, int l, int r, int add){
	push(v);
	if(rmq[v].l > r || rmq[v].r < l || l > r){
		return;
	}
	if(rmq[v].l >= l && rmq[v].r <= r){
		rmq[v].add += add;
		push(v);
		return;
	}
	update(v * 2, l, r, add);
	update(v * 2 + 1, l, r, add);
	calc(v);
}

pii get(int v, int l, int r){
	push(v);
	if(rmq[v].l > r || rmq[v].r < l || l > r){
		return mp(inf, 0);
	}
	if(rmq[v].l >= l && rmq[v].r <= r){
		return mp(rmq[v].val, rmq[v].cnt);
	}
	pii res = get(v * 2, l, r), res2 = get(v * 2 + 1, l, r);
	if(res2.fs < res.fs){
		res = res2;
	}
	else{
		if(res2.fs == res.fs){
			res.sc += res2.sc;
		}
	}
	return res;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n - 1; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	sz = 0;
	dfs(0);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &A[i], &B[i]);
		A[i]--;
		B[i]--;
	}
	maxv = 1;
	while(maxv < n){
		maxv *= 2;
	}
	for(int i = 0; i < maxv; i++){
		rmq[i + maxv].cnt = 1;
		rmq[i + maxv].l = rmq[i + maxv].r = i;
	}
	for(int i = maxv - 1; i > 0; i--){
		calc(i);
		rmq[i].l = rmq[i * 2].l;
		rmq[i].r = rmq[i * 2 + 1].r;
	}
	for(int i = 0; i < m; i++){
		int a = A[i], b = B[i];
		if(max(lft[a], lft[b]) <= min(rgh[a], rgh[b])){
			int l = min(lft[a], lft[b]), r = max(rgh[a], rgh[b]);
			q1[l].pb(query(i, l, 0, -1, -1));
			q2[r].pb(query(i, l, 0, -1, -1));
		}
		else{
			if(lft[a] > lft[b]){
				swap(a, b);
			}
			q1[lft[a]].pb(query(i, lft[a], 0, -1, -1));
			q2[rgh[a]].pb(query(i, lft[a], 0, -1, -1));
			q1[lft[b]].pb(query(i, lft[b], 1, lft[a], rgh[a]));
			q2[rgh[b]].pb(query(i, lft[b], 1, lft[a], rgh[a]));
		}
	}
	set <pii> s;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < sz(q1[i]); j++){
			s.insert(mp(q1[i][j].l, q1[i][j].num));
			if(q1[i][j].t == 1){
				update(1, q1[i][j].lft, q1[i][j].rgh, 1);
			}
		}
		int g = i;
		if(sz(s) > 0){
			g = s.begin()->fs;
		}
		ans[lst[i]] += i - g;
		pii cur = get(1, 0, g - 1);
		if(cur.fs == 0){
			ans[lst[i]] += g - cur.sc;
		}
		else{
			ans[lst[i]] += g;
		}
		for(int j = 0; j < sz(q2[i]); j++){
			s.erase(mp(q2[i][j].l, q2[i][j].num));
			if(q2[i][j].t == 1){
				update(1, q2[i][j].lft, q2[i][j].rgh, -1);
			}
		}
	}
	for(int i = 0; i < maxv; i++){
		rmq[i + maxv].val = rmq[i + maxv].add = 0;
		rmq[i + maxv].cnt = 1;
	}
	for(int i = maxv - 1; i > 0; i--){
		rmq[i].add = 0;
		calc(i);
	}
	s.clear();
	for(int i = 0; i < n; i++){
		q1[i].clear();
		q2[i].clear();
	}
	for(int i = 0; i < m; i++){
		int a = A[i], b = B[i];
		if(max(lft[a], lft[b]) <= min(rgh[a], rgh[b])){
			int l = min(lft[a], lft[b]), r = max(rgh[a], rgh[b]);
			q1[r].pb(query(i, r, 0, -1, -1));
			q2[l].pb(query(i, r, 0, -1, -1));
		}
		else{
			if(rgh[a] < rgh[b]){
				swap(a, b);
			}
			q1[rgh[a]].pb(query(i, rgh[a], 0, -1, -1));
			q2[lft[a]].pb(query(i, rgh[a], 0, -1, -1));
			q1[rgh[b]].pb(query(i, rgh[b], 1, lft[a], rgh[a]));
			q2[lft[b]].pb(query(i, rgh[b], 1, lft[a], rgh[a]));
		}
	}
	for(int i = n - 1; i >= 0; i--){
		for(int j = 0; j < sz(q1[i]); j++){
			s.insert(mp(q1[i][j].l, q1[i][j].num));
			if(q1[i][j].t == 1){
				update(1, q1[i][j].lft, q1[i][j].rgh, 1);
			}
		}
		int g = i;
		if(sz(s) > 0){
			set <pii> :: iterator it = s.end();
			it--;
			g = it->fs;
		}
		ans[lst[i]] += g - i;
		pii cur = get(1, g + 1, n - 1);
		if(cur.fs == 0){
			ans[lst[i]] += n - g - 1 - cur.sc;
		}
		else{
			ans[lst[i]] += n - g - 1;
		}
		for(int j = 0; j < sz(q2[i]); j++){
			s.erase(mp(q2[i][j].l, q2[i][j].num));
			if(q2[i][j].t == 1){
				update(1, q2[i][j].lft, q2[i][j].rgh, -1);
			}
		}
	}
	for(int i = 0; i < n; i++){
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}