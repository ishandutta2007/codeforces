// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;

const int N = (int) 0, mod = (int) 0;
const int maxn = 100;
int a[maxn][maxn];
bool mark[maxn];
typedef pair<int,int> pii;
bool isok(int x0,int y0,int x2,int y2){
	if(x0 == x2)
		return 1;
	if(y0 == y2)
		return 1;
	return 0;
}
void doo(pii p){
	cout << char('a' + p.first) << p.second + 1 << ' ';
}
int main() {
	int n;
	cin >> n;
	if(n <= 4){
		if(n == 2)
			cout << "a1 h1 h8" << endl;
		if(n == 3)
			cout << "a1 b1 h1 h8" << endl;
		if(n == 4)
			cout << "a1 b1 c1 h1 h8" << endl;
		return 0;
	}
	n--;
	int cur = 1;
	for(int i=0; i<8; i++){
		if(i % 2 == 0){
			a[i][0] = cur++;
			for(int j=2; j<8; j++)
				a[i][j] = cur++;
			a[i][1] = cur++;
		}
		else if(i != 7){
			a[i][1] = cur++;
			for(int j=2; j<8; j++)
				a[i][j] = cur++;
			a[i][0] = cur++;
		}
		else{
			a[i][1] = cur++;
			for(int j=2; j<7; j++)
				a[i][j] = cur++;
			a[i][0] = cur++;
			a[i][7] = cur++;
		}
	}/*
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}*/
	int x = 0, y = 0;
	int rem = n;
	cur = 2;
	vector<pair<int,int> > ans;
	ans.push_back({0, 0});
	mark[0] = 1;
	for(int i=0; i+3<n; i++){
		rem--;
		int nx = -1, ny = -1;
		for(int j=0; j<8; j++){
			for(int k=0; k<8; k++){
				if(a[j][k] == cur){
					nx = j, ny = k;
				}
			}
		}
		if(nx == -1)
			assert(0);
		mark[nx * 8 + ny] = 1;
		x = nx, y = ny;
		ans.push_back({x, y});
		cur++;
	}
	if(rem != 3){
		cout << "a1 h1 h8" << endl;
		return 0;
	}
	for(int i=0; i<63; i++){
		for(int j=0; j<63; j++){
			for(int k=0; k<63; k++){
				if(i != j && i != k && j != k && !mark[i] && !mark[j] && !mark[k]){
					int ix = i/8, iy = i%8;
					if(!isok(x, y, ix, iy))
						continue;
					int jx = j/8, jy = j%8;
					if(!isok(ix, iy, jx, jy))
						continue;
					int kx = k/8, ky = k%8;
					if(!isok(jx, jy, kx, ky))
						continue;
					if(!isok(kx, ky, 7, 7))
						continue;
					for(auto t : ans)
						doo(t);
					doo({ix, iy});
					doo({jx, jy});
					doo({kx, ky});
					doo({7, 7});
					cout << endl;
					return 0;
				}
			}
		}
	}
}