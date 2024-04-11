#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <string>
#include <map>
#include <functional>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k;
	int t, n, m, q;
	scanf("%d %d %d", &n, &m, &q);
	long long answer = 0;
	for(i=0; i<n; i++) {
		int len = min(2*m, 2*i+1);
		answer += len*(len+1)/2;
	}
	for(i=0; i<m; i++) {
		int len = min(2*n, 2*i+1);
		answer += len*(len+1)/2;
	}
	answer -= n*m;
	//printf("%lld\n", answer);
	int a[n][m] = {};
	for(ql=0; ql<q; ql++) {
		int x, y;
		scanf("%d %d", &x, &y);
		x--, y--;
		int c1, c2;
		int xp, yp;
		c1 = 0;
		xp = x, yp = y;
		do {
			if(c1%2 == 0) {
				yp--;
			} else {
				xp--;
			}
			c1++;
		} while(0<=xp && xp<n && 0<=yp && yp<m && !a[xp][yp]);
		c1--;
		c2 = 0;
		xp = x, yp = y;
		do {
			if(c2%2 == 0) {
				xp++;
			} else {
				yp++;
			}
			c2++;
		} while(0<=xp && xp<n && 0<=yp && yp<m && !a[xp][yp]);
		c2--;
		if(a[x][y] == 0) {
			answer -= (c1+c2+1)*(c1+c2)/2;
			answer += c1*(c1-1)/2+c2*(c2-1)/2;
		} else {
			answer += (c1+c2+1)*(c1+c2)/2;
			answer -= c1*(c1-1)/2+c2*(c2-1)/2;
		}
		c1 = 0;
		xp = x, yp = y;
		do {
			if(c1%2 == 0) {
				xp--;
			} else {
				yp--;
			}
			c1++;
		} while(0<=xp && xp<n && 0<=yp && yp<m && !a[xp][yp]);
		c1--;
		c2 = 0;
		xp = x, yp = y;
		do {
			if(c2%2 == 0) {
				yp++;
			} else {
				xp++;
			}
			c2++;
		} while(0<=xp && xp<n && 0<=yp && yp<m && !a[xp][yp]);
		c2--;
		if(a[x][y] == 0) {
			answer -= (c1+c2+1)*(c1+c2)/2;
			answer += c1*(c1-1)/2+c2*(c2-1)/2;
			answer--;
		} else {
			answer += (c1+c2+1)*(c1+c2)/2;
			answer -= c1*(c1-1)/2+c2*(c2-1)/2;
			answer++;
		}
		a[x][y] = 1-a[x][y];
		printf("%lld\n", answer);
	}
}