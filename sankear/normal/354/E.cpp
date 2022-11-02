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
const int LEN = 19;
const int OST = 4;

const int ch[] = {0, 4, 7};

int a[LEN + 10];
ll ans[10], p10[LEN + 10];
bool can[LEN + 10][OST + 10];
bool can_sum[10][60];
int prev_sum[10][60];
int prev[LEN + 10][OST + 10], val[LEN + 10][OST + 10];

inline void init(){
	p10[0] = 1;
	for(int i = 1; i < LEN; i++){
		p10[i] = p10[i - 1] * 10;
	}
	can_sum[0][0] = true;
	for(int i = 0; i < 6; i++){
		for(int j = 0; j <= 7 * i; j++){
			if(can_sum[i][j]){
				for(int z = 0; z < 3; z++){
					can_sum[i + 1][j + ch[z]] = true;
					prev_sum[i + 1][j + ch[z]] = ch[z];
				}
			}
		}
	}
}

inline void solve(){
	ll n;
	scanf(LLD, &n);
	int len = 0;
	while(n > 0){
		a[len++] = n % 10;
		n /= 10;
	}
	for(int i = 0; i <= len; i++){
		for(int j = 0; j <= OST; j++){
			can[i][j] = false;
		}
	}
	can[0][0] = true;
	for(int i = 0; i < len; i++){
		for(int j = 0; j <= OST; j++){
			if(can[i][j]){
				for(int z = 0; z <= 42; z++){
					if(can_sum[6][z] && (j + z) % 10 == a[i]){
						int nj = (j + z) / 10;
						can[i + 1][nj] = true;
						prev[i + 1][nj] = j;
						val[i + 1][nj] = z;
					}
				}
			}
		}
	}
	if(!can[len][0]){
		puts("-1");
		return;
	}
	int i = len, j = 0;
	while(i > 0){
		a[i - 1] = val[i][j];
		j = prev[i][j];
		i--;
	}
	for(int i = 0; i < 6; i++){
		ans[i] = 0;
	}
	for(int i = 0; i < len; i++){
		int j = 6, z = a[i];
		while(j > 0){
			ans[j - 1] += p10[i] * prev_sum[j][z];
			z -= prev_sum[j][z];
			j--;
		}
	}
	for(int i = 0; i < 6; i++){
		printf(LLD" ", ans[i]);
	}
	puts("");
}

int main(){
	init();
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		solve();
	}
	return 0;
}