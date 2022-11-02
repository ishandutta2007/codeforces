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
const int N = int(1e6) + 100;

int n;
int f[N], st[N], ans[N];
vector <pii> q[N];
char s[N];

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

int main(){
	gets(s);
	n = strlen(s);
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int l, r;
		scanf("%d %d", &l, &r);
		l--;
		r--;
		q[r].pb(mp(l, i));
	}
	int k = 0, sum = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '('){
			st[k++] = i;
		}
		else{
			if(k > 0){
				sum++;
				add(st[--k]);
			}
		}
		for(int j = 0; j < sz(q[i]); j++){
			ans[q[i][j].sc] = sum - (q[i][j].fs > 0 ? get(q[i][j].fs - 1) : 0);
		}
	}
	for(int i = 0; i < m; i++){
		printf("%d\n", 2 * ans[i]);
	}
	return 0;
}