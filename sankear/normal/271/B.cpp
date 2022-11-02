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
 
const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));

int a[555][555];
bool prime[200200];
int ans[200200];

inline void init(){
	for(int i = 2; i <= 200000; i++){
		prime[i] = true;
	}
	for(int i = 2; i * i <= 200000; i++){
		if(prime[i]){
			for(int j = i * i; j <= 200000; j += i){
				prime[j] = false;
			}
		}
	}
	int last = 200000;
	for(int i = 200000; i >= 0; i--){
		if(prime[i]){
			last = i;
		}
		ans[i] = last - i;
	}
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	init();
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &a[i][j]);
		}
	}
	int ANS = inf;
	for(int i = 0; i < n; i++){
		int res = 0;
		for(int j = 0; j < m; j++){
			res += ans[a[i][j]];
		}
		ANS = min(ANS, res);
	}
	for(int i = 0; i < m; i++){
		int res = 0;
		for(int j = 0; j < n; j++){
			res += ans[a[j][i]];
		}
		ANS = min(ANS, res);
	}
	printf("%d\n", ANS);
	return 0;
}