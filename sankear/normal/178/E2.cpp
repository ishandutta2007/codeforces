#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;

const double magic = 10;
const double pi = acos((double)-1);

int n;
vector <pii> lst;
bool used[2020][2020];
int a[2020][2020];

inline bool good(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < n && a[x][y] == 1;
}

void dfs(int x, int y){
	used[x][y] = true;
	lst.pb(mp(x, y));
	for(int i = -1; i <= 1; i++){
		for(int j = -1; j <= 1; j++){
			int xx = x + i, yy = y + j;
			if(good(xx, yy) && !used[xx][yy]){
				dfs(xx, yy);
			}
		}
	}
}

inline double sqr(double a){
	return a * a;
}

inline double getdist(double x1, double y1, double x2, double y2){
	return sqrt(sqr(x2 - x1) + sqr(y2 -y1));
}

int main(){
	//freopen("robotnavigation.in", "r", stdin);
	//freopen("robotnavigation.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &a[i][j]);
		}
	}
	int ansa = 0, ansb = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[i][j] == 1 && !used[i][j]){
				lst.clear();
				dfs(i, j);
				if(lst.size() < 147){
					continue;
				}
				int sx = 0, sy = 0;
				for(int z = 0; z < (int)lst.size(); z++){
					sx += lst[z].first;
					sy += lst[z].second;
				}
				sx /= (int)lst.size();
				sy /= (int)lst.size();
				double dist = 0, r = 0;
				for(int z = 0; z < (int)lst.size(); z++){
					dist += getdist(sx, sy, lst[z].first, lst[z].second);
					r = max(r, getdist(sx, sy, lst[z].first, lst[z].second));
				}
				dist /= (int)lst.size();
				double val = 0;
				for(int z = 0; z < (int)lst.size(); z++){
					val += sqr(getdist(sx, sy, lst[z].first, lst[z].second) - dist);
				}
				val = sqrt(val / ((int)lst.size() * (lst.size() - 1)));
				//printf("%.18lf\n", fabs(val * pi * sqr(r) - val * lst.size()));
				if(fabs(val * pi * sqr(r)  - val * lst.size()) < magic){
					ansa++;
				}
				else{
					ansb++;
				}
			}
		}
	}
	printf("%d %d\n", ansa, ansb);
	return 0;
}