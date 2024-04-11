#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define M 1000000007
#define N 211111
using namespace std;
typedef pair<int,int> pt;

int n, kk;
int x[N], y[N];
vector<int> vx[N], vy[N];
long long yy[N];
int pp[N], xx[1222000];

void add(int x, int y) {
	long long e = (x + 1) * 100111ll + (y + 1);
	int o = e % 1000007;
	yy[++kk] = e;
	pp[kk] = xx[o];
	xx[o] = kk;
}

bool fin(int x, int y) {
	if (x < 0 || x > 100000) return 0;
	if (y < 0 || y > 100000) return 0;
	long long e = (x + 1) * 100111ll + (y + 1);
	int o = e % 1000007;
	for (int w = xx[o]; w; w = pp[w]) if (yy[w] == e) return 1;
	return 0;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x[i], &y[i]);
		vx[x[i]].pb(y[i]);
		vy[y[i]].pb(x[i]);
		add(x[i], y[i]);
	}
	for (int i = 0; i <= 100000; i++) {
		sort(vx[i].begin(), vx[i].end());
		sort(vy[i].begin(), vy[i].end());
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int xx = x[i];
		int yy = y[i];
		int d;
		if (vx[xx].size() < vy[yy].size()) {
			for (int j = 0; j < vx[xx].size(); j++) {
				if (vx[xx][j] == yy) break;
				d = yy - vx[xx][j];
				if (fin(xx - d, yy) && fin(xx - d, yy - d)) ans++;
			}
		} else {
			for (int j = 0; j < vy[yy].size(); j++) {
				if (vy[yy][j] == xx) break;
				d = xx - vy[yy][j];
				if (fin(xx, yy - d) && fin(xx - d, yy - d)) ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}