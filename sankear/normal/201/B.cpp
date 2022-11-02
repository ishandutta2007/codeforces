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
 
const ll inf = ll(1e18);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));

ll c[1010][1010];

inline ll sqr(ll a){
	return a * a;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf(LLD, &c[i][j]);
		}
	}
	ll A = 0, B = 0, C = 0, D = 0, E = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			A += c[i][j] * sqr(4 * i + 2);
			B += c[i][j] * (4 * i + 2);
			C += c[i][j];
			D += c[i][j] * sqr(4 * j + 2);
			E += c[i][j] * (4 * j + 2);
		}
	}
	ll ans = inf;
	int x, y;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			ll res = A - 8 * i * B + 16 * sqr(i) * C + D - 8 * j * E + 16 * sqr(j) * C;
			if(res < ans){
				ans = res;
				x = i;
				y = j;
			}
		}
	}
	printf(LLD"\n%d %d\n", ans, x, y);
	return 0;
}