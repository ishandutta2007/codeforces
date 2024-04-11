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
#define link _link

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

pair <double, int> p[5050];
int d[5050][5050];

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d %lf", &p[i].sc, &p[i].fs);
	}
	sort(p + 1, p + n + 1);
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			d[i][j] = inf;
		}
	}
	for(int i = 0; i <= m; i++){
		d[0][i] = 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			d[i][j] = min(d[i][j - 1], d[i - 1][j] + (p[i].sc != j));
		}
	}
	int ans = inf;
	for(int i = 1; i <= m; i++){
		ans = min(ans, d[n][i]);
	}
	printf("%d\n", ans);
	return 0;
}