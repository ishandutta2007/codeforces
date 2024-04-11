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
const int N = 5005;

int a[N];
int l[N][N], r[N][N];

int main(){
	//cerr << (sizeof(l) + sizeof(r)) / 1024 / 1024 << endl;
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			l[i][j] = (j > 0 ? l[i][j - 1] : 0) + (a[i] < a[j]);
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = n - 1; j >= 0; j--){
			r[i][j] = (j + 1 < n ? r[i][j + 1] : 0) + (a[i] > a[j]);
		}
	}
	int res = inf, cnt, cur = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			if(a[i] < a[j]){
				cur++;
			}
		}
	}
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			int cur_res = cur - (i > 0 ? l[i][i - 1] : 0) - r[i][i + 1] - l[j][j - 1] - (j + 1 < n ? r[j][j + 1] : 0) + (a[i] > a[j]);
			cur_res += (i > 0 ? l[j][i - 1] : 0) + r[j][i + 1] + (j + 1 < n ? r[i][j + 1] : 0) + l[i][j - 1];
			if(cur_res < res){
				res = cur_res;
				cnt = 0;
			}
			if(cur_res == res){
				cnt++;
			}
		}
	}
	printf("%d %d\n", res, cnt);
	return 0;
}