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
#define y1 _fjdksgjldfjl
 
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

struct tq{
	int x1, y1, x2, y2, num;
	tq(){}
	tq(int _x1, int _y1, int _x2, int _y2, int _num){
		x1 = _x1;
		y1 = _y1;
		x2 = _x2;
		y2 = _y2;
		num = _num;
	}
};

int m, maxv;
char a[1111][555];
bitset <555> l[1111][555], r[1111][555];
vector <tq> q[1111];
bool good[600600];

void dfs(int v, int lg, int rg){
	if(v < maxv){
		int mid = (lg + rg) / 2;
		dfs(v * 2, lg, mid);
		dfs(v * 2 + 1, mid + 1, rg);
		for(int i = 0; i < sz(q[v]); i++){
			bitset <555> cur = (r[q[v][i].x1][q[v][i].y1] & l[q[v][i].x2][q[v][i].y2]);
			good[q[v][i].num] = cur.any();
		}
		for(int i = mid; i >= lg; i--){
			for(int j = m - 1; j >= 0; j--){
				if(a[i][j] == '.'){
					r[i][j] = r[i + 1][j];
					if(j + 1 < m){
						r[i][j] |= r[i][j + 1];
					}
				}
			}
		}
		for(int i = mid + 1; i <= rg; i++){
			for(int j = 0; j < m; j++){
				if(a[i][j] == '.'){
					l[i][j] = l[i - 1][j];
					if(j - 1 >= 0){
						l[i][j] |= l[i][j - 1];
					}
				}
			}
		}
	}
	else{
		for(int i = 0; i < sz(q[v]); i++){
			bitset <555> cur = (r[q[v][i].x1][q[v][i].y1] & l[q[v][i].x2][q[v][i].y2]);
			good[q[v][i].num] = cur.any();
		}
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("arrays.in", "r", stdin);
	//freopen("arrays.out", "w", stdout);
	int n;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf(" %c", &a[i][j]);
		}
	}
	maxv = 1;
	while(maxv < n){
		maxv *= 2;
	}
	for(int i = n; i < maxv; i++){
		for(int j = 0; j < m; j++){
			a[i][j] = '#';
		}
	}
	int k;
	scanf("%d", &k);
	for(int i = 0; i < k; i++){
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		x1--;
		y1--;
		x2--;
		y2--;
		int lg = x1 + maxv, rg = x2 + maxv;
		while(lg < rg){
			lg /= 2;
			rg /= 2;
		}
		q[lg].pb(tq(x1, y1, x2, y2, i));
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == '.'){
				l[i][j].set(j, true);
				r[i][j].set(j, true);
			}
		}
		for(int j = 1; j < m; j++){
			if(a[i][j] == '.'){
				l[i][j] |= l[i][j - 1];
			}
		}
		for(int j = m - 2; j >= 0; j--){
			if(a[i][j] == '.'){
				r[i][j] |= r[i][j + 1];
			}
		}
	}
	dfs(1, 0, maxv - 1);
	for(int i = 0; i < k; i++){
		if(good[i]){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	return 0;
}