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

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));

inline int gcd(int a, int b){
	while(b > 0){
		a %= b;
		swap(a, b);
	}
	return a;
}

int main(){
	int n;
	scanf("%d", &n);
	int max_a = -inf, g = 0;
	for(int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		max_a = max(max_a, a);
		g = gcd(g, a);
	}
	if((max_a / g - n) % 2 == 0){
		puts("Bob");
	}
	else{
		puts("Alice");
	}
	return 0;
}