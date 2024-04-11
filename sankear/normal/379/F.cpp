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
#include <complex>
#include <queue>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define LLD "%lld"
#else
#define eprintf(...) 42
#define LLD "%I64d"
#endif
#define fs first
#define sc second
#define next _next
#define prev _prev
#define hash _hash
#define link _link
#define y0 yy0
#define y1 yy1

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;
typedef long double ld;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(1e6) + 100;
const int LOG = 20;

int h[N];
int p[LOG][N];

inline int get_lca(int a, int b){
	if(h[a] < h[b]){
		swap(a, b);
	}
	for(int i = LOG - 1; i >= 0; i--){
		if(p[i][a] != -1 && h[p[i][a]] >= h[b]){
			a = p[i][a];
		}
	}
	if(a == b){
		return a;
	}
	for(int i = LOG - 1; i >= 0; i--){
		if(p[i][a] != p[i][b]){
			a = p[i][a];
			b = p[i][b];
		}
	}
	return p[0][a];
}

inline int path(int a, int b){
	int c = get_lca(a, b);
	return h[a] + h[b] - 2 * h[c];
}

int main(){
	int q;
	scanf("%d", &q);
	int n = 4 + 2 * q;
	for(int i = 0; i < LOG; i++){
		for(int j = 0; j < n; j++){
			p[i][j] = -1;
		}
	}
	p[0][1] = p[0][2] = p[0][3] = 0;
	h[1] = h[2] = h[3] = 1;
	int cur = 4, a = 1, b = 2, len = 2;
	for(int i = 0; i < q; i++){
		int v;
		scanf("%d", &v);
		v--;
		p[0][cur] = p[0][cur + 1] = v;
		h[cur] = h[cur + 1] = h[v] + 1;
		for(int j = 1; j < LOG; j++){
			if(p[j - 1][cur] != -1){
				p[j][cur] = p[j - 1][p[j - 1][cur]];
			}
			if(p[j - 1][cur + 1] != -1){
				p[j][cur + 1] = p[j - 1][p[j - 1][cur + 1]];
			}
		}
		if(path(a, cur) > len){
			b = cur;
			len++;
		}
		else{
			if(path(b, cur) > len){
				a = cur;
				len++;
			}
		}
		cur += 2;
		printf("%d\n", len);
	}
	return 0;
}