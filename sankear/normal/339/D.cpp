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
const int N = 17;

int n;
int rmq[(1 << (N + 2))];

inline void update(int pos, int val){
	pos += (1 << n);
	rmq[pos] = val;
	int lev = 0;
	while(pos > 1){
		pos /= 2;
		if(lev == 0){
			rmq[pos] = (rmq[pos * 2] | rmq[pos * 2 + 1]);
		}
		else{
			rmq[pos] = (rmq[pos * 2] ^ rmq[pos * 2 + 1]);
		}
		lev = 1 - lev;
	}
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < (1 << n); i++){
		int cur;
		scanf("%d", &cur);
		update(i, cur);
	}
	for(int i = 0; i < m; i++){
		int pos, val;
		scanf("%d %d", &pos, &val);
		pos--;
		update(pos, val);
		printf("%d\n", rmq[1]);
	}
	return 0;
}