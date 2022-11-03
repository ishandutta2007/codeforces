#pragma comment(linker, "/STACK:20000000")
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

const int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

const int SIZE = 2048;
const int RAD = 3;
const double BLACK_THRES = 0.5;
const int COMP_SIZE_THRES = 100;

int n;
int matr[SIZE][SIZE];
double smooth[SIZE][SIZE];

inline bool good(int x, int y) {
	return !(x < 0 || x >= n || y < 0 || y >= n);
}

inline bool isblack(int x, int y) { return smooth[x][y] >= BLACK_THRES; }

typedef pair<int, int> pii;

int k;
vector<vector<pii> > comps;
bool used[SIZE][SIZE];
void DFS(int x, int y) {
	used[x][y] = true;
	comps[k].push_back(pii(x, y));
	for (int d = 0; d<4; d++) {
		int nx = x + dir[d][0];
		int ny = y + dir[d][1];
		if (!good(nx, ny) || used[nx][ny] || !isblack(nx, ny))
			continue;
		DFS(nx, ny);
	}
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d", &n);
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
			scanf("%d", &matr[i][j]);

	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++) {
			int cnt = 0;
			int sum = 0;
			for (int di = -RAD; di <= RAD; di++)
				for (int dj = -RAD; dj <= RAD; dj++) {
					int qi = i + di;
					int qj = j + dj;
					if (!good(qi, qj)) continue;
					cnt++;
					sum += matr[qi][qj];
				}
			smooth[i][j] = double(sum) / cnt;
		}

	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++) if (isblack(i, j) && !used[i][j]) {
			comps.push_back(vector<pii>());
			DFS(i, j);
			k++;
		}

	int circles = 0, rects = 0;
	for (int i = 0; i<k; i++) {
		const vector<pii> &shape = comps[i];
//		Eo(comps[i].size());
		if (shape.size() < COMP_SIZE_THRES) continue;

		double cx = 0.0, cy = 0.0;
		for (int j = 0; j<shape.size(); j++) {
			cx += shape[j].first;
			cy += shape[j].second;
		}
		cx /= shape.size();
		cy /= shape.size();
//		Eo(cx);
//		Eo(cy);

		double radius = sqrt(shape.size() / (2.0*acos(0.0)));
		static const int HISTO_RES = 2;
        double histo[HISTO_RES * 2 + 1] = {0.0};
        for (int j = 0; j<shape.size(); j++) {
			double dx = shape[j].first - cx;
			double dy = shape[j].second - cy;
			double dist = sqrt(dx*dx + dy*dy);

			dist /= radius;
			int cell = int(dist * HISTO_RES);
			if (cell > HISTO_RES*2) continue;
			histo[cell] += 1.0;
        }
        for (int i = 0; i<=HISTO_RES*2; i++) {
        	double avgrad = radius * (i+0.5) / HISTO_RES;
        	double deltarad = radius / HISTO_RES;
        	double sq = 2.0*acos(0.0) * avgrad * deltarad;
	        histo[i] /= sq;
	    }
//        for (int i = 0; i<=HISTO_RES*2; i++) Ef("%6.3lf ", histo[i]); Ef("\n");

		if (histo[2] < 0.05)
			circles++;
		else
			rects++;
	}

	printf("%d %d\n", circles, rects);
	return 0;
}