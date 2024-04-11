#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <complex>
#include <cassert>

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

typedef long long ll;
typedef long long llong;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));

int a[1010][1010];
int r[1010], c[1010];

int main(){
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("painting.in", "r", stdin);
    //freopen("painting.out", "w", stdout);
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &a[i][j]);	
		}
	}
	for(int i = 0; i < n; i++){
		r[i] = i;	
	}
	for(int i = 0; i < m; i++){
		c[i] = i;	
	}
	for(int i = 0; i < k; i++){
		char ch;
		int x, y;
		scanf(" %c %d %d", &ch, &x, &y);
		x--;
		y--;
		if(ch == 'c'){
			swap(c[x], c[y]);	
		}
		if(ch == 'r'){
			swap(r[x], r[y]);	
		}
		if(ch == 'g'){
			printf("%d\n", a[r[x]][c[y]]);	
		}
	}
	return 0;
}