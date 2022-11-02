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
const int N = int(2e5);

struct tq{
	int l, r;
};

struct tr{
	ll sum, add;
	int l, r;
};

int n;
int a[N + 10], pos[N + 10];
tq q[N + 10];
int ans[N + 10];
vector <pii> v[N + 10];
int f[N + 10];

inline void add(int pos){
	while(pos < n){
		f[pos]++;
		pos = (pos | (pos + 1));
	}
}

inline int get(int pos){
	int res = 0;
	while(pos >= 0){
		res += f[pos];
		pos = (pos & (pos + 1)) - 1;
	}
	return res;
}

inline void gen(){
	freopen("input.txt", "w", stdout);
	int n = int(2e5), m = int(2e5);
	cout << n << " " << m << endl;
	for(int i = 0; i < n; i++){
		a[i] = i + 1; 
	}
	random_shuffle(a, a + n);
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	for(int i = 0; i < m; i++){
		int l = rand() % n, r = l + rand() % (n - l);
		cout << l + 1 << " " << r + 1 << endl;
	}
	exit(0);
}

int main(){
	//gen();
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		pos[a[i]] = i;
	}
	for(int i = 0; i < m; i++){
		scanf("%d %d", &q[i].l, &q[i].r);
		q[i].l--;
		q[i].r--;
	}
	for(int i = 0; i < m; i++){
		v[q[i].r].pb(mp(q[i].l, i));
	}
	int all = 0;
	for(int i = 0; i < n; i++){
		for(int j = a[i]; j <= n; j += a[i]){
			if(pos[j] <= i){
				all++;
				add(pos[j]);
			}
		}
		for(int j = 0; j < sz(v[i]); j++){
			ans[v[i][j].sc] += all - get(v[i][j].fs - 1);
		}
	}
	for(int i = 0; i < n; i++){
		v[i].clear();
	}
	for(int i = 0; i < m; i++){
		v[q[i].l].pb(mp(q[i].r, i));
	}
	for(int i = 0; i < n; i++){
		f[i] = 0;
	}
	for(int i = n - 1; i >= 0; i--){
		for(int j = 2 * a[i]; j <= n; j += a[i]){
			if(pos[j] > i){
				add(pos[j]);
			}
		}
		for(int j = 0; j < sz(v[i]); j++){
			ans[v[i][j].sc] += get(v[i][j].fs);
		}
	}
	for(int i = 0; i < m; i++){
		printf("%d\n", ans[i]);
	}
	return 0;
}