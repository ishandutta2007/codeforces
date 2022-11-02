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
const int steps = 16;

struct tr{
	int l, r;
};

int k;
bool good[100100];
int h[100100], lft[100100], rgh[100100], val[100100];
vi v[100100];
tr rmq[280280];
int lst[2000200];
int p[steps + 1][100100];

void dfs(int a, int b){
	h[a] = b;
	lft[a] = k;
	val[k++] = b;
	for(int i = 0; i < sz(v[a]); i++){
		p[0][v[a][i]] = a;
		dfs(v[a][i], b + 1);
	}
	rgh[a] = k - 1;
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
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		good[i] = true;
	}
	for(int i = 0; i < n; i++){
		int prev;
		scanf("%d", &prev);
		prev--;
		if(prev != -1){
			good[i] = false;
			v[prev].pb(i);
		}
	}
	for(int i = 0; i <= steps; i++){
		for(int j = 0; j < n; j++){
			p[i][j] = -1;
		}
	}
	k = 0;
	for(int i = 0; i < n; i++){
		if(good[i]){
			dfs(i, 0);
		}
	}
	for(int i = 1; i <= steps; i++){
		for(int j = 0; j < n; j++){
			if(p[i - 1][j] == -1){
				continue;
			}
			p[i][j] = p[i - 1][p[i - 1][j]];
		}
	}
	int maxv = 1;
	while(maxv < n){
		maxv *= 2;
	}
	int sz = 0;
	for(int i = 0; i < n; i++){
		lst[++sz] = val[i];
		rmq[i + maxv].l = rmq[i + maxv].r = sz;
	}
	for(int i = maxv - 1; i > 0; i--){
		int oldsz = sz, j = rmq[i * 2].l, z = rmq[i * 2 + 1].l;
		while(j > 0 && j <= rmq[i * 2].r && z > 0 && z <= rmq[i * 2 + 1].r){
			if(lst[j] < lst[z]){
				lst[++sz] = lst[j++];
			}
			else{
				lst[++sz] = lst[z++];
			}
		}
		while(j > 0 && j <= rmq[i * 2].r){
			lst[++sz] = lst[j++];
		}
		while(z > 0 && z <= rmq[i * 2 + 1].r){
			lst[++sz] = lst[z++];
		}
		if(oldsz < sz){
			rmq[i].l = oldsz + 1;
			rmq[i].r = sz;
		}
	}
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		if(i > 0){
			printf(" ");
		}
		int ver, len;
		scanf("%d %d", &ver, &len);
		int need = len;
		ver--;
		bool fl = false;
		for(int j = steps; j >= 0; j--){
			if((1 << j) <= len){
				if(p[j][ver] == -1){
					fl = true;
					break;
				}
				ver = p[j][ver];
				len -= (1 << j);
			}
		}
		if(fl){
			printf("0");
			continue;
		}
		int res = 0, l = lft[ver] + maxv, r = rgh[ver] + maxv;
		while(l <= r){
			if(l % 2 != 0 && rmq[l].l > 0){
				int gl = -1, cl = rmq[l].l, cr = rmq[l].r;
				while(cl <= cr){
					int mid = (cl + cr) / 2;
					if(lst[mid] == h[ver] + need){
						gl = mid;
						cr = mid - 1;
						continue;
					}
					if(lst[mid] < h[ver] + need){
						cl = mid + 1;
					}
					else{
						cr = mid - 1;
					}
				}
				if(gl != -1){
					int gr = gl;
					cl = gl + 1;
					cr = rmq[l].r;
					while(cl <= cr){
						int mid = (cl + cr) / 2;
						if(lst[mid] == h[ver] + need){
							gr = mid;
							cl = mid + 1;
						}
						else{
							cr = mid - 1;
						}
					}
					res += gr - gl + 1;
				}
			}
			l = (l + 1) / 2;
			if(r % 2 == 0 && rmq[r].l > 0){
				int gl = -1, cl = rmq[r].l, cr = rmq[r].r;
				while(cl <= cr){
					int mid = (cl + cr) / 2;
					if(lst[mid] == h[ver] + need){
						gl = mid;
						cr = mid - 1;
						continue;
					}
					if(lst[mid] < h[ver] + need){
						cl = mid + 1;
					}
					else{
						cr = mid - 1;
					}
				}
				if(gl != -1){
					int gr = gl;
					cl = gl + 1;
					cr = rmq[r].r;
					while(cl <= cr){
						int mid = (cl + cr) / 2;
						if(lst[mid] == h[ver] + need){
							gr = mid;
							cl = mid + 1;
						}
						else{
							cr = mid - 1;
						}
					}
					res += gr - gl + 1;
				}
			}
			r = (r - 1) / 2;
		}
		printf("%d", res - 1);
	}
	printf("\n");
	return 0;
}