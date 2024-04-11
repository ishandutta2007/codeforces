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
const int N = 24;
const int MOD = int(1e9) + 7;

int a[N], b[N];
ll sum[(1 << N)];
int d[(1 << N)];

inline void norm(int &a){
	while(a >= MOD){
		a -= MOD;
	}
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//cerr << "mem = " << (sizeof(d) + sizeof(sum)) / 1024 / 1024 << endl;
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int k;
	scanf("%d", &k);
	for(int i = 0; i < k; i++){
		scanf("%d", &b[i]);
	}
	int all = (1 << n);
	d[0] = 1;
	sum[0] = 0;
	for(int i = 0; i < all; i++){
		bool fl = false;
		for(int j = 0; j < k; j++){
			if(sum[i] == b[j]){
				fl = true;
				break;
			}
		}
		if(fl){
			d[i] = 0;
		}
		for(int j = 0; j < n; j++){
			if((i & (1 << j)) == 0){
				int ni = (i | (1 << j));
				sum[ni] = sum[i] + a[j];
				d[ni] += d[i];
				norm(d[ni]);
			}
		}
	}
	printf("%d\n", d[all - 1]);
	return 0;
}