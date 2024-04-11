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

int n;
vi v[100100];

inline void check1(){
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(sz(v[i]) == 1){
			cnt++;
		}
		if(sz(v[i]) > 2){
			return;
		}
	}
	if(cnt != 2){
		return;
	}
	printf("bus topology\n");
	exit(0);
}

inline void check2(){
	for(int i = 0; i < n; i++){
		if(sz(v[i]) != 2){
			return;
		}
	}
	printf("ring topology\n");
	exit(0);
}

inline void check3(){
	int best = 0;
	for(int i = 1; i < n; i++){
		if(sz(v[i]) > sz(v[best])){
			best = i;
		}
	}
	if(sz(v[best]) != n - 1){
		return;
	}
	for(int i = 0; i < n; i++){
		if(i == best){
			continue;
		}
		if(sz(v[i]) != 1){
			return;
		}
	}
	printf("star topology\n");
	exit(0);
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	check1();
	check2();
	check3();
	printf("unknown topology\n");
	return 0;
}