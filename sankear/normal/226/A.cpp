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

int m;
ll a[2][2], b[2][2], c[2][2];

void calc(int n){
	if(n == 1){
		a[0][0] = 3;
		a[0][1] = 2;
		a[1][0] = 0;
		a[1][1] = 1;
		return;
	}
	if(n % 2 == 0){
		calc(n / 2);
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				b[i][j] = 0;
				for(int z = 0; z < 2; z++){
					b[i][j] = (b[i][j] + a[i][z] * a[z][j]) % m;
				}
			}
		}
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				a[i][j] = b[i][j];
			}
		}
	}
	else{
		calc(n - 1);
		b[0][0] = 3;
		b[0][1] = 2;
		b[1][0] = 0;
		b[1][1] = 1;
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				c[i][j] = 0;
				for(int z = 0; z < 2; z++){
					c[i][j] = (c[i][j] + a[i][z] * b[z][j]) % m;
				}
			}
		}
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				a[i][j] = c[i][j];
			}
		}
	}
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int n;
	scanf("%d %d", &n, &m);
	calc(n);
	printf(LLD"\n", a[0][1] % m);
	return 0;
}