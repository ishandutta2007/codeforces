#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstring>
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

typedef long long ll;
typedef long long llong;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;

const ll inf = ll(1e15);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));

int maxv;
bool used[100100];
ll d[100100];
vector <pii> v[100100];
vi lst[100100], t[100100];
pair <ll, int> rmq[280280];

inline void update(int a, ll b){
	a += maxv;	
	rmq[a].fs = b;
	while(a > 1){
		a /= 2;
		rmq[a] = min(rmq[a * 2], rmq[a * 2 + 1]);
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a--;
		b--;
		v[a].pb(mp(b, c));
		v[b].pb(mp(a, c));
	}
	for(int i = 0; i < n; i++){
		int k;
		scanf("%d", &k);
		for(int j = 0; j < k; j++){
			int t;
			scanf("%d", &t);
			lst[i].pb(t);
		}
	}
	for(int i = 0; i < n; i++){
		t[i].resize(sz(lst[i]));
		for(int j = sz(lst[i]) - 1; j >= 0; j--){
			if(j == sz(lst[i]) - 1 || lst[i][j] + 1 != lst[i][j + 1]){
				t[i][j] = lst[i][j] + 1;	
			}
			else{
				t[i][j] = t[i][j + 1];	
			}
		}
	}
	for(int i = 0; i < n; i++){
		d[i] = inf;	
	}
	maxv = 1;
	while(maxv < n){
		maxv *= 2;	
	}
	for(int i = 0; i < maxv; i++){
		rmq[i + maxv] = mp(inf, i);	
	}
	for(int i = maxv - 1; i > 0; i--){
		rmq[i] = min(rmq[i * 2], rmq[i * 2 + 1]);	
	}
	d[0] = 0;
	update(0, 0);
	for(int i = 0; i < n; i++){
		pii cur = rmq[1];
		if(cur.fs == inf){
			break;	
		}
		used[cur.sc] = true;
		update(cur.sc, inf);
		ll cur_time = d[cur.sc];
		int pos = lower_bound(lst[cur.sc].begin(), lst[cur.sc].end(), cur_time) - lst[cur.sc].begin();
		if(pos < sz(lst[cur.sc]) && lst[cur.sc][pos] == cur_time){
			cur_time = t[cur.sc][pos];
		}
		for(int j = 0; j < sz(v[cur.sc]); j++){
			if(cur_time + v[cur.sc][j].sc < d[v[cur.sc][j].fs]){
				d[v[cur.sc][j].fs] = cur_time + v[cur.sc][j].sc;
				if(!used[v[cur.sc][j].fs]){
					update(v[cur.sc][j].fs, d[v[cur.sc][j].fs]);	
				}
			}
		}
	}
	if(d[n - 1] == inf){
		printf("-1\n");
		return 0;
	}
	printf("%I64d\n", d[n - 1]);
	return 0;
}