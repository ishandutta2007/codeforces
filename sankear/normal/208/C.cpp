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

bool go[200][200], can[200][200];
ll all[200];
ll f[200][200];
int q[200], d[200], perm[200];

inline bool cmp(int a, int b){
	return d[a] < d[b];
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
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		can[a][b] = can[b][a] = true;
	}
	for(int i = 0; i < n; i++){
		d[i] = inf;
	}
	d[0] = 0;
	all[0] = 1;
	int l = 0, r = 1;
	while(l < r){
		int v = q[l++];
		for(int i = 0; i < n; i++){
			if(can[v][i] && d[i] > d[v] + 1){
				d[i] = d[v] + 1;
				all[i] = all[v];
				q[r++] = i;
			}
			else{
				if(can[v][i] && d[i] == d[v] + 1){
					all[i] += all[v];
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		perm[i] = i;
	}
	sort(perm, perm + n, cmp);
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(can[perm[i]][perm[j]] && d[perm[j]] == d[perm[i]] + 1){
				go[i][j] = true;
			}
		}
	}
	int pos = -1;
	for(int i = 0; i < n; i++){
		if(perm[i] == n - 1){
			pos = i;
			break;
		}
	}
	double ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int z = 0; z < n; z++){
				f[j][z] = 0;
			}
		}
		f[0][0] = 1;
		for(int j = 0; j < n; j++){
			for(int z = 0; z < n; z++){
				if(f[j][z] == 0){
					continue;
				}
				for(int h = j + 1; h < n; h++){
					if(go[j][h]){
						if(j == i || h == i){
							f[h][z + 1] += f[j][z];
						}
						else{
							f[h][z] += f[j][z];
						}
					}
				}
			}
		}
		double res = 0;
		for(int j = 0; j < n; j++){
			res += (double(f[pos][j]) * j) / all[n - 1];
		}
		ans = max(ans, res);
	}
	printf("%.18lf\n", ans);
	return 0;
}