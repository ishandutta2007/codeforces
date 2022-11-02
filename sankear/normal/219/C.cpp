#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstring>
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

typedef long long ll;
typedef long long llong;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));

int f[30], best[30], d[30];
char s[500500];
char p[500500][30];

void path(int n, int k){
	if(n == 0){
		return;	
	}
	path(n - 1, p[n][k]);
	s[n - 1] = 'A' + k;
}

int main(){
 	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf(" %c", &s[i]);	
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < k; j++){
			f[j] = d[j] + (s[i - 1] - 'A' != j);
			p[i][j] = best[j];
		}
		for(int j = 0; j < k; j++){
			d[j] = inf;
		}
		int cur = inf, cb = -1;
		for(int j = 0; j < k; j++){
			if(cur < d[j]){
				d[j] = cur;
				best[j] = cb;
			}
			if(f[j] < cur){
				cur = f[j];
				cb = j;
			}
		}
		cur = inf;
		cb = -1;
		for(int j = k - 1; j >= 0; j--){
			if(cur < d[j]){
				d[j] = cur;
				best[j] = cb;
			}
			if(f[j] < cur){
				cur = f[j];
				cb = j;
			}
		}
	}
	int ans = inf, best = -1;
	for(int i = 0; i < k; i++){
		if(f[i] < ans){
			ans = f[i];
			best = i;
		}
	}
	path(n, best);
	printf("%d\n%s\n", ans, s);
	return 0;
}