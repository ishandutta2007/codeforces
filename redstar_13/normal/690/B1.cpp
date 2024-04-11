#include <bits/stdc++.h>
#define rep(i, a, b) for(i=(a); i<(b); i++)
using namespace std;
template <class T> inline void smin(T &a, T b) {if(a>b)a=b;}
template <class T> inline void smax(T &a, T b) {if(a<b)a=b;}

#define NN 111
#define beyond(x, y) (x<0 || y<0 || x>=n || y>=n)
char grid[NN][NN];
int main() {
	
	int n, i, j, sx, sy, ex, ey;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%s", grid[i]);
	sx=sy=111; ex=ey=-1;
	rep(i, 0, n) rep(j, 0, n) {
		if(grid[i][j]=='4') {
			smax(ex, i); smin(sx, i);
			smax(ey, j); smin(sy, j);
		}
	}
	if(sx>ex || sy>ey) {
		puts("No");
		return 0;
	}
	sx--; sy--;
	ex++; ey++;
	for(i=sx; i<=ex; i++) {
		for(j=sy; j<=ey; j++) {
			if(beyond(i, j)) continue;
			if((i==sx || i==ex) && (j==sy || j==ey)) {
				if(grid[i][j]!='1') break;
			} else if((i==sx || i==ex) || (j==sy || j==ey)) {
				if(grid[i][j]!='2') break;
			} else {
				if(grid[i][j]!='4') break;
			}
		}
		if(j<=ey) break;
	}
	if(i<=ex) {puts("No");return 0;}
	rep(i,0, n) {
		rep(j,0, n){
			if(i<sx || i>ex || j<sy || j>ey) {
				if(grid[i][j]!='0') break;
			}
		}
		if(j<n) break;
	}
	if(i<n) puts("No");
	else puts("Yes");

	return 0;
}