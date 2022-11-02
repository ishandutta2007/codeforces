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
const int base = int(1e4);

char s[200];
int a[200];
int ans[200];
int d[200][2][2][2][2][200];

inline void inttolong(int *a, int b){
	if(b == 0){
		a[0] = 1;
		a[1] = 0;
		return;
	}
	a[0] = 0;
	while(b > 0){
		a[++a[0]] = b % base;
		b /= base;
	}
}

inline void write(int *a){
	printf("%d", a[a[0]]);
	for(int i = a[0] - 1; i > 0; i--){
		printf("%04d", a[i]);
	}
}

inline void sum(int *a, int *b){
	if(a[0] < b[0]){
		for(int i = a[0] + 1; i <= b[0]; i++){
			a[i] = 0;
		}
		a[0] = b[0];
	}
	if(a[0] > b[0]){
		for(int i = b[0] + 1; i <= a[0]; i++){
			b[i] = 0;
		}
	}
	int ost = 0;
	for(int i = 1; i <= a[0]; i++){
		a[i] += b[i] + ost;
		if(a[i] >= base){
			a[i] -= base;
			ost = 1;
			continue;
		}
		ost = 0;
	}
	if(ost > 0){
		a[++a[0]] = 1;
	}
}

int main(){
#ifdef HOME
	double start = clock();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
#endif
	//cout << sizeof(d) / 1024 / 1024 << endl;
	scanf("%s", s);
	int n = strlen(s);
	for(int i = 0; i < n; i++){
		a[i] = (s[i] == 'B');
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 2; j++){
			for(int z = 0; z < 2; z++){
				for(int x = 0; x < 2; x++){
					for(int y = 0; y < 2; y++){
						inttolong(d[i][j][z][x][y], 0);
					}
				}
			}
		}
	}
	inttolong(d[0][0][0][0][0], 1);
	inttolong(d[0][1][1][0][0], 1);
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < 2; j++){
			for(int z = 0; z < 2; z++){
				for(int x = 0; x < 2; x++){
					for(int y = 0; y < 2; y++){
						for(int zz = 0; zz < 2; zz++){
							if(i == 0){
								if(x != 0 || y != 0){
									continue;
								}
								if(z == 0 && zz == 1){
									if(a[0] != 1 || a[1] != 0){
										continue;
									}
									sum(d[i + 1][j][zz][1][1], d[i][j][z][x][y]);
								}
								else{
									sum(d[i + 1][j][zz][0][0], d[i][j][z][x][y]);
								}
							}
							else{
								if(y == 0){
									if(z == 0 && zz == 1){
										if(a[i] != 1 || a[i + 1] != 0){
											continue;
										}
										sum(d[i + 1][j][zz][x][1], d[i][j][z][x][y]);
									}
									else{
										if(a[i] != z){
											continue;
										}
										sum(d[i + 1][j][zz][x][0], d[i][j][z][x][y]);
									}
								}
								else{
									sum(d[i + 1][j][zz][x][0], d[i][j][z][x][y]);
								}
							}
						}
					}
				}
			}
		}
	}
	inttolong(ans, 0);
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			for(int z = 0; z < 2; z++){
				for(int h = 0; h < 2; h++){
					if(z == 0 && h == 0){
						if(i == 1 && j == 0){
							if(a[0] != 0 || a[n - 1] != 1){
								continue;
							}
						}
						else{
							if(a[0] != i || a[n - 1] != j){
								continue;
							}
						}
					}
					else{
						if(z == 0 && a[0] != i){
							continue;
						}
						if(h == 0 && a[n - 1] != j){
							continue;
						}
					}
					sum(ans, d[n - 1][i][j][z][h]);
				}
			}
		}
	}
	write(ans);
	printf("\n");
	return 0;
}