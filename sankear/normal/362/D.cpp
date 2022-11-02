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
#define len(s) int((s).size())
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
typedef long long int64;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned long long lint;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef complex <double> tc;

const ll inf = ll(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(1e5) + 100;

int prev[N], rank[N];
ll sum[N];
set <pair <ll, int> > s;
vector <pii> ans;

int get(int a){
	if(prev[a] != a){
		prev[a] = get(prev[a]);
	}
	return prev[a];
}

inline void add(int a, int b, int c){
	a = get(a);
	b = get(b);
	if(a == b){
		sum[a] += c;
		return;
	}
	if(rank[a] < rank[b]){
		swap(a, b);
	}
	prev[b] = a;
	sum[a] += sum[b];
	if(rank[a] == rank[b]){
		rank[a]++;
	}
	sum[a] += c;
}

int main(){
	int n, m, p, q;
	scanf("%d %d %d %d", &n, &m, &p, &q);
	for(int i = 0; i < n; i++){
		prev[i] = i;
		rank[i] = 1;
	}
	for(int i = 0; i < m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a--;
		b--;
		add(a, b, c);
	}
	for(int i = 0; i < n; i++){
		if(get(i) == i){
			s.insert(mp(sum[i], i));
		}
	}
	while(sz(s) > q && p > 0){
		int a = s.begin()->sc;
		s.erase(s.begin());
		int b = s.begin()->sc;
		s.erase(s.begin());
		ans.pb(mp(a, b));
		add(a, b, min(sum[a] + sum[b] + 1, inf));
		a = get(a);
		s.insert(mp(sum[a], a));
		p--;
	}
	if(p == 0){
		if(sz(s) != q){
			puts("NO");
			return 0;
		}
		puts("YES");
		for(int i = 0; i < sz(ans); i++){
			printf("%d %d\n", ans[i].fs + 1, ans[i].sc + 1);
		}
		return 0;
	}
	if(sz(s) == n || sz(s) != q){
		puts("NO");
		return 0;
	}
	puts("YES");
	for(int i = 0; i < sz(ans); i++){
		printf("%d %d\n", ans[i].fs + 1, ans[i].sc + 1);
	}
	for(int i = 0; i < n; i++){
		if(get(i) != i){
			for(int j = 0; j < p; j++){
				printf("%d %d\n", i + 1, get(i) + 1);
			}
			break;
		}
	}
	return 0;
}