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

bool need[1000100], good[1000100];
int ans[1000100];
tc a[2098000];

inline void fail(){
	printf("NO\n");
	exit(0);
}

inline void fft(tc *a, int n, bool fl){
	for(int i = 1, j = 0; i < n; i++){
		int bit = n / 2;
		for(; j >= bit; bit /= 2){
			j -= bit;
		}
		j += bit;
		if(i < j){
			swap(a[i], a[j]);
		}
	}
	for(int len = 2; len <= n; len *= 2){
		double ang = 2 * pi / len * (fl ? -1 : 1);
		tc wlen(cos(ang), sin(ang));
		for(int i = 0; i < n; i += len){
			tc w(1);
			for(int j = 0; j < len / 2; j++){
				tc u = a[i + j], v = a[i + j + len / 2] * w;
				a[i + j] = u + v;
				a[i + j + len / 2] = u - v;
				w *= wlen;
			}
		}
	}
	if(fl){
		for(int i = 0; i < n; i++){
			a[i] /= n;
		}
	}
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		int cur;
		scanf("%d", &cur);
		need[cur] = true;
		a[cur] = 1;
	}
	for(int i = 1; i <= m; i++){
		if(need[i]){
			for(int j = i + i; j <= m; j += i){
				if(!need[j]){
					fail();
				}
			}
		}
	}
	int maxv = 1;
	while(maxv < m + 1){
		maxv *= 2;
	}
	maxv *= 2;
	fft(a, maxv, false);
	for(int i = 0; i < maxv; i++){
		a[i] *= a[i];
	}
	fft(a, maxv, true);
	int k = 0;
	for(int i = 1; i <= m; i++){
		int cur = int(a[i].real() + 0.5);
		if(cur > 0){
			if(!need[i]){
				fail();
			}
			continue;
		}
		if(need[i]){
			if(good[i]){
				continue;
			}
			ans[k++] = i;
			for(int j = i; j <= m; j += i){
				good[j] = true;
			}
		}
	}
	printf("YES\n%d\n", k);
	for(int i = 0; i < k; i++){
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}