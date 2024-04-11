#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <queue>
#include <cassert>

using namespace std;

//#define HOME
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define next _next
#define rank _rank
#define prev _prev
#define sz(s) int((s).size())

typedef long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;

const double eps = 1e-9;
const double pi = acos(double(-1));
const int inf = int(1e9);

int x[5050], y[5050];

inline double sqr(double a){
	return a * a;
}

int main(){
#ifdef HOME
	double start = clock();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("destination.in", "r", stdin);
	//freopen("destination.out", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &x[i]);
	}
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d", &y[i]);
	}
	int k;
	scanf("%d", &k);
	int minz = inf;
	for(int i = 0; i < k; i++){
		int z;
		scanf("%d", &z);
		minz = min(minz, z);
	}
	int a, b;
	scanf("%d %d", &a, &b);
	double ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			ans = max(ans, sqr(x[i]) * y[j] * b / (double(y[j]) * b + double(minz) * a));
		}
	}
	ans = sqrt(ans);
	printf("%.18lf\n", ans);
#ifdef HOME
	printf("time = %.18lf\n", (clock() - start) / CLOCKS_PER_SEC);
#endif
	return 0;
}