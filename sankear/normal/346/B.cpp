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
const int N = 100;
const int M = 26;

char a[N + 10], b[N + 10], c[N + 10], tmp[N + 10];
int go[N + 10][M + 10];
int d[N + 10][N + 10][N + 10], t[N + 10][N + 10][N + 10], p[N + 10][N + 10][N + 10];

int main(){
	gets(a);
	gets(b);
	gets(c);
	int n = strlen(a), m = strlen(b), k = strlen(c);
	for(int i = 0; i < k; i++){
		for(int j = 0; j < M; j++){
			int ptr = 0;
			for(int z = 0; z < i; z++){
				tmp[ptr++] = c[z];
			}
			tmp[ptr++] = 'A' + j;
			for(int z = i + 1; z >= 0; z--){
				bool fl = true;
				for(int h = 0; h < z; h++){
					if(tmp[ptr - z + h] != c[h]){
						fl = false;
						break;
					}
				}
				if(fl){
					go[i][j] = z;
					break;
				}
			}
		}
	}
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			for(int z = 0; z < k; z++){
				d[i][j][z] = -inf;
			}
		}
	}
	d[0][0][0] = 0;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			for(int z = 0; z < k; z++){
				if(d[i][j][z] == -inf){
					continue;
				}
				if(i < n){
					if(d[i + 1][j][z] < d[i][j][z]){
						d[i + 1][j][z] = d[i][j][z];
						t[i + 1][j][z] = 1;
					}
				}
				if(j < m){
					if(d[i][j + 1][z] < d[i][j][z]){
						d[i][j + 1][z] = d[i][j][z];
						t[i][j + 1][z] = 2;
					}
				}
				if(i < n && j < m && a[i] == b[j] && go[z][a[i] - 'A'] < k){
					if(d[i + 1][j + 1][go[z][a[i] - 'A']] < d[i][j][z] + 1){
						d[i + 1][j + 1][go[z][a[i] - 'A']] = d[i][j][z] + 1;
						t[i + 1][j + 1][go[z][a[i] - 'A']] = 3;
						p[i + 1][j + 1][go[z][a[i] - 'A']] = z;
					}
				}
			}
		}
	}
	int ans = -inf, best = -1;
	for(int i = 0; i < k; i++){
		if(d[n][m][i] > ans){
			ans = d[n][m][i];
			best = i;
		}
	}
	if(ans == 0){
		puts("0");
		return 0;
	}
	int ptr = 0, i = n, j = m, z = best;
	while(i > 0 || j > 0){
		if(t[i][j][z] == 1){
			i--;
			continue;
		}
		if(t[i][j][z] == 2){
			j--;
			continue;
		}
		tmp[ptr++] = a[i - 1];
		int nz = p[i][j][z];
		i--;
		j--;
		z = nz;
	}
	tmp[ptr] = 0;
	reverse(tmp, tmp + ptr);
	puts(tmp);
	return 0;
}