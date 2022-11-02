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
const int N = 100;

bool used[2 * N + 10];
char a[N + 10][N + 10];
int q[2 * N + 10], p[2 * N + 10];
int c[2 * N + 10][2 * N + 10], f[2 * N + 10][2 * N + 10];

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	gets(a[0]);
	for(int i = 0; i < n; i++){
		gets(a[i]);
	}
	int s = 2 * n, t = s + 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[i][j] == '.'){
				c[i][j + n] = 1;
			}
		}
	}
	for(int i = 0; i < n; i++){
		c[s][i] = 1;
		c[i + n][t] = inf;
	}
	bool good = true;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= t; j++){
			used[j] = false;
		}
		used[s] = true;
		int l = 0, r = 1;
		q[0] = s;
		while(l < r && !used[t]){
			int cur = q[l++];
			for(int j = 0; j <= t; j++){
				if(c[cur][j] - f[cur][j] > 0 && !used[j]){
					used[j] = true;
					p[j] = cur;
					q[r++] = j;
				}
			}
		}
		if(!used[t]){
			good = false;
			break;
		}
		for(int j = t; j != s; j = p[j]){
			f[p[j]][j]++;
			f[j][p[j]]--;
		}
	}
	if(good){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(f[i][j + n] > 0){
					printf("%d %d\n", i + 1, j + 1);
				}
			}
		}
		return 0;
	}
	for(int i = 0; i <= t; i++){
		for(int j = 0; j <= t; j++){
			c[i][j] = f[i][j] = 0;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[i][j] == '.'){
				c[i][j + n] = 1;
			}
		}
	}
	for(int i = 0; i < n; i++){
		c[s][i] = inf;
		c[i + n][t] = 1;
	}
	good = true;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= t; j++){
			used[j] = false;
		}
		used[s] = true;
		int l = 0, r = 1;
		q[0] = s;
		while(l < r && !used[t]){
			int cur = q[l++];
			for(int j = 0; j <= t; j++){
				if(c[cur][j] - f[cur][j] > 0 && !used[j]){
					used[j] = true;
					p[j] = cur;
					q[r++] = j;
				}
			}
		}
		if(!used[t]){
			good = false;
			break;
		}
		for(int j = t; j != s; j = p[j]){
			f[p[j]][j]++;
			f[j][p[j]]--;
		}
	}
	if(good){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(f[i][j + n] > 0){
					printf("%d %d\n", i + 1, j + 1);
				}
			}
		}
		return 0;
	}
	puts("-1");
	return 0;
}