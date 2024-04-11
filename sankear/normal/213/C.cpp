#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <queue>
#include <cassert>

using namespace std;

//#define HOME
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define next _next
#define rank _rank
#define prev _prev
#define sz(s) int((s).size())

typedef long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;

const double eps = 1e-9;
const double pi = acos(double(-1));
const int inf = int(1e9);

int a[303][303], sum[303][303];
int d[303][303][303], f[303][303];

int main(){
#ifdef HOME
	double start = clock();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("bonus.in", "r", stdin);
	//freopen("bonus.out", "w", stdout);
#endif
	//cout << (sizeof(a) + sizeof(sum) + sizeof(d) + sizeof(f)) / 1024 / 1024 << endl;
	/*cout << 300 << endl;
	for(int i = 0; i < 300; i++){
		for(int j = 0; j < 300; j++){
			cout << -1000 << " ";
		}
		cout << endl;
	}
	return 0;*/
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int z = j; z < n; z++){
				d[i][j][z] = -inf;
			}
		}
	}
	d[0][0][0] = a[0][0];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			sum[i][j] = ((j > 0) ? sum[i][j - 1] : 0) + a[j][i];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int z = j; z < n; z++){
				if(i > 0){
					d[i][j][z] = max(d[i][j][z], f[j][z] + sum[i][j] + ((j < z) ? a[z][i] : 0));
				}
				if(j == z && j > 0){
					d[i][j][z] = max(d[i][j][z], d[i][j - 1][z - 1] + a[j][i]);
				}
				if(z - 1 >= j){
					d[i][j][z] = max(d[i][j][z], d[i][j][z - 1] + a[z][i]);
				}
			}
		}
		if(i + 1 < n){
			for(int j = 0; j < n; j++){
				for(int z = j; z < n; z++){
					f[j][z] = max(((j > 0) ? f[j - 1][z] : -inf), d[i][j][z] - ((j > 0) ? sum[i + 1][j - 1] : 0));
				}
			}
		}
	}
	printf("%d\n", d[n - 1][n - 1][n - 1]);
#ifdef HOME
	printf("time = %.18lf\n", (clock() - start) / CLOCKS_PER_SEC);
#endif
	return 0;
}