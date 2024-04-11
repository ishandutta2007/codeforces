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
const int N = int(5e4);
const int LEN = 50;

int ptr;
int last[30];
char s[N + 10], ans[N + 10];
int d[N + 10][LEN + 10], p[N + 10][LEN + 10];
int next[N + 10][30], prev[N + 10][30];

void path(int pos, int len){
	if(len > 1){
		path(p[pos][len], len - 1);
	}
	ans[ptr++] = s[pos];
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//cerr << "mem = " << (sizeof(d) + sizeof(p)) / 1024 / 1024 << endl;
	gets(s);
	int n = strlen(s);
	for(int i = 0; i < 26; i++){
		last[i] = -1;
	}
	for(int i = 0; i <= n; i++){
		for(int j = 0; j < 26; j++){
			prev[i][j] = last[j];
		}
		if(i < n){
			last[s[i] - 'a'] = i;
		}
	}
	for(int i = 0; i < 26; i++){
		last[i] = -1;
	}
	for(int i = n - 1; i >= 0; i--){
		for(int j = 0; j < 26; j++){
			next[i][j] = last[j];
		}
		last[s[i] - 'a'] = i;
	}
	for(int i = 0; i < n; i++){
		for(int j = 1; j <= LEN; j++){
			d[i][j] = -1;
		}
	}
	for(int i = 0; i < n; i++){
		if(prev[n][s[i] - 'a'] > i){
			d[i][1] = prev[n][s[i] - 'a'];
		}
		for(int j = 1; j < LEN; j++){
			if(d[i][j] == -1){
				continue;
			}
			for(int z = 0; z < 26; z++){
				if(next[i][z] != -1 && prev[d[i][j]][z] > next[i][z]){
					if(prev[d[i][j]][z] > d[next[i][z]][j + 1]){
						d[next[i][z]][j + 1] = prev[d[i][j]][z];
						p[next[i][z]][j + 1] = i;
					}
				}
			}
		}
	}
	// check 100
	for(int i = 0; i < n; i++){
		if(d[i][50] > i){
			ptr = 0;
			path(i, 50);
			printf("%s", ans);
			reverse(ans, ans + 50);
			printf("%s\n", ans);
			return 0;
		}
	}
	int len = 1, x, y;
	for(int i = 0; i < n; i++){
		for(int j = 1; j <= LEN; j++){
			if(d[i][j] > i){
				if(2 * j > len){
					len = 2 * j;
					x = i;
					y = j;
				}
				if(d[i][j] > i + 1 && 2 * j + 1 > len){
					len = 2 * j + 1;
					x = i;
					y = j;
				}
			}
		}
	}
	if(len == 1){
		printf("%c\n", s[0]);
		return 0;
	}
	ptr = 0;
	path(x, y);
	printf("%s", ans);
	if(len % 2 != 0){
		printf("%c", s[x + 1]);
	}
	reverse(ans, ans + ptr);
	printf("%s\n", ans);
	return 0;
}