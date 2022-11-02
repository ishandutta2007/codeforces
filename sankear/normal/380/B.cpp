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
#include <complex>
#include <queue>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define LLD "%lld"
#else
#define eprintf(...) 42
#define LLD "%I64d"
#endif
#define fs first
#define sc second
#define next _next
#define prev _prev
#define hash _hash
#define link _link
#define y0 yy0
#define y1 yy1

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;
typedef long double ld;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int SIZE = int(1e6) + 100;
const int X = int(1e6) + 100;
const int N = 7070;

int used[X];
int s[SIZE];
vector <pair <pii, int> > q[N];

inline void init(){
	for(int i = 0; (1 << i) < SIZE; i++){
		s[(1 << i)] = 1;
	}
	for(int i = 1; i <= SIZE; i++){
		s[i] += s[i - 1];
	}
}

inline int left(int pos){
	return pos + s[pos - 1];
}

inline int right(int pos){
	return pos + s[pos];
}

int main(){
	init();
	int cur = 1;
	for(int i = 0; i < 7000; i++){
		cur = cur + s[cur];
	}
	cerr << cur << endl;
	int n, m;
	scanf("%d %d", &n, &m);
	int step = 0;
	for(int i = 0; i < m; i++){
		int t;
		scanf("%d", &t);
		if(t == 1){
			int lev, l, r, x;
			scanf("%d %d %d %d", &lev, &l, &r, &x);
			q[lev].pb(mp(mp(l, r), x));
			continue;
		}
		int lev, num;
		scanf("%d %d", &lev, &num);
		int l = num, r = num;
		step++;
		int ans = 0;
		for(int j = lev; j <= n; j++){
			for(int z = 0; z < sz(q[j]); z++){
				if(max(l, q[j][z].fs.fs) <= min(r, q[j][z].fs.sc)){
					if(used[q[j][z].sc] != step){
						used[q[j][z].sc] = step;
						ans++;
					}
				}
			}
			l = left(l);
			r = right(r);
		}
		printf("%d\n", ans);
	}
	return 0;
}