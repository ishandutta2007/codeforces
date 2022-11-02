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

int a[5050], sum[5050];
int d[5050][5050], f[5050][5050];

inline int get_sum(int l, int r){
	return sum[r] - (l > 0 ? sum[l - 1] : 0);	
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//cerr << (sizeof(a) + sizeof(sum) + sizeof(d) + sizeof(f)) / 1024 / 1024 << endl;
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);	
	}
	for(int i = 0; i < n; i++){
		sum[i] = (i > 0 ? sum[i - 1] : 0) + a[i];	
	}
	for(int i = 0; i < n; i++){
		d[i][0] = i;
		int ptr = i - 1;
		for(int j = i; j > 0; j--){
			ptr = min(ptr, j - 1);
			while(ptr - 1 >= 0 && get_sum(ptr - 1, j - 1) <= get_sum(j, i)){
				ptr--;	
			}
			d[i][j] = (get_sum(ptr, j - 1) <= get_sum(j, i) ? i - j + f[j - 1][ptr] : inf);
		}
		f[i][i] = d[i][i];
		for(int j = i - 1; j >= 0; j--){
			f[i][j] = min(f[i][j + 1], d[i][j]);	
		}
	}
	int ans = inf;
	for(int i = n - 1; i >= 0; i--){
		ans = min(ans, d[n - 1][i]);	
	}
	printf("%d\n", ans);
	return 0;
}