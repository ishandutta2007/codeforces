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
const int LEN = 100, LOG = 30;

char a[LEN + 100], c[LEN + 100];
int go[LOG + 10][LEN + 100], add[LOG + 10][LEN + 100];
int go2[LOG + 10][LEN + 100], add2[LOG + 10][LEN + 100];

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int b, d;
	scanf("%d %d", &b, &d);
	scanf("%s %s", a, c);
	int n = strlen(a), m = strlen(c);
	for(int i = n; i > 0; i--){
		a[i] = a[i - 1];
	}
	a[0] = 'z' + 1;
	n++;
	for(int i = 0; i < m; i++){
		bool fl = false;
		for(int j = 0; j < n; j++){
			if(a[j] == c[i]){
				fl = true;
				break;
			}
		}
		if(!fl){
			puts("0");
			return 0;
		}
	}
	for(int i = 0; i < n; i++){
		int pos = i, res = 0;
		for(int j = 0; j < m; j++){
			pos++;
			if(pos >= n){
				pos = 0;
				res++;
			}
			while(a[pos] != c[j]){
				pos++;
				if(pos >= n){
					pos = 0;
					res++;
				}
			}
		}
		go[0][i] = pos;
		add[0][i] = res;
	}
	for(int i = 1; i <= LOG; i++){
		for(int j = 0; j < n; j++){
			go[i][j] = go[i - 1][go[i - 1][j]];
			add[i][j] = min(add[i - 1][j] + add[i - 1][go[i - 1][j]], inf);
		}
	}
	for(int i = 0; i < n; i++){
		int pos = i, res = 0, cur = d;
		for(int j = LOG; j >= 0; j--){
			if((1 << j) <= cur){
				res = min(res + add[j][pos], inf);
				pos = go[j][pos];
				cur -= (1 << j);
			}
		}
		go2[0][i] = pos;
		add2[0][i] = res;
	}
	for(int i = 1; i <= LOG; i++){
		for(int j = 0; j < n; j++){
			go2[i][j] = go2[i - 1][go2[i - 1][j]];
			add2[i][j] = min(add2[i - 1][j] + add2[i - 1][go2[i - 1][j]], inf);
		}
	}
	int pos = 0, res = 0, ans = 0;
	for(int i = LOG; i >= 0; i--){
		if(add2[i][pos] + res + 1 <= b){
			ans += (1 << i);
			res += add2[i][pos];
			pos = go2[i][pos];
		}
	}
	printf("%d\n", ans);
	return 0;
}