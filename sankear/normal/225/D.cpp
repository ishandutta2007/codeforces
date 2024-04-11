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

const int inf = 10000;
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m, k, mask;
char a[15][15];
int used[15][15];
short d[15][15][65536];
char qx[15 * 15 * 65536], qy[15 * 15 * 65536];
int qm[15 * 15 * 65536];
pii p[15];

inline bool good(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m;	
}

void dfs(int x, int y){
	for(int i = 0; i < 4; i++){
		if(good(x + dx[i], y + dy[i]) && a[x + dx[i]][y + dy[i]] == '0' + k + 1){
			mask += i * (1 << (2 * (k - 1)));
			k++;
			dfs(x + dx[i], y + dy[i]);
		}
	}
}

int main(){
 	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf(" %c", &a[i][j]);	
		}
	}
	k = mask = 0;
	int l = 0, r = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == '1'){
				k++;
				dfs(i, j);
				for(int z = 0; z < n; z++){
					for(int h = 0; h < m; h++){
						for(int x = 0; x < (1 << (2 * (k - 1))); x++){
							d[z][h][x] = inf;
						}	
					}
				}
				d[i][j][mask] = 0;
				qx[0] = i;
				qy[0] = j;
				qm[0] = mask;
			}
		}
	}
	int step = 0;
	while(l < r){
		int x = qx[l], y = qy[l], mask = qm[l++];
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i], ny = y + dy[i];
			if(good(nx, ny) && a[nx][ny] != '#'){
				p[0] = mp(nx, ny);
				p[1] = mp(x, y);
				int cur = mask, cx = x, cy = y;
				for(int j = 0; j < k - 2; j++){
					cx += dx[cur % 4];
					cy += dy[cur % 4];
					p[2 + j] = mp(cx, cy);
					cur /= 4;
				}
				step++;
				bool fl = true;
				for(int j = 0; j < k; j++){
					if(used[p[j].fs][p[j].sc] == step){
						fl = false;
						break;
					}
					used[p[j].fs][p[j].sc] = step;
				}
				if(!fl){
					continue;	
				}
				int nmask = 0;
				for(int j = 0; j < k - 1; j++){
					for(int z = 0; z < 4; z++){
						if(p[j].fs + dx[z] == p[j + 1].fs && p[j].sc + dy[z] == p[j + 1].sc){
							nmask += z * (1 << (2 * j));
							break;
						}
					}
				}
				if(d[nx][ny][nmask] > d[x][y][mask] + 1){
					d[nx][ny][nmask] = d[x][y][mask] + 1;
					qx[r] = nx;
					qy[r] = ny;
					qm[r++] = nmask;
				}
			}
		}
	}
	int ans = inf;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] != '@'){
				continue;	
			}
			for(int z = 0; z < (1 << (2 * (k - 1))); z++){
				ans = min(ans, int(d[i][j][z]));
			}
		}
	}
	if(ans == inf){
		ans = -1;	
	}
	printf("%d\n", ans);
	return 0;
}