#include <bits/stdc++.h>
using namespace std;
#define N 2005

const int inf = 1e7;

int qs, q[N], m, n;
bool vis[N][N];
struct PNT{
	int x, y;
} b[N], r[N];

bool cmpb(PNT X, PNT Y){
	if(X.y != Y.y) return X.y < Y.y;
	return X.x < Y.x;
}

bool cmpr(PNT X, PNT Y){
	if(X.x != Y.x) return X.x < Y.x;
	return X.y < Y.y;
}

bool check(int tim){
	memset(vis, 0, sizeof vis);
	int i, j, aa, bb, k, cc, dd;
	for(i = 0; i < n; i++){
		aa = b[i].x - 2 * tim;
		bb = b[i].x + 2 * tim;
		for(j = i + 1; j < n; j++){
			if(b[i].y < b[j].y) break;
			else if(b[j].x - bb <= 2 * tim) bb = b[j].x + 2 * tim, i = j;
			else break;
		}
		qs = 0;
		for(j = 0; j < m; j++) if(r[j].x <= bb && r[j].x >= aa){

			cc = r[j].y - 2 * tim;
			dd = r[j].y + 2 * tim;
			for(k = j + 1; k < m; k++){
				if(r[j].x < r[k].x) break;
				else if(r[k].y - dd <= 2 * tim) dd = r[k].y + 2 * tim, j = k;
				else break;
			}
			if(cc <= b[i].y && dd >= b[i].y) q[qs++] = j;
		}
		for(j = 0; j < qs; j++){
			for(k = j + 1; k < qs; k++){
				if(vis[q[j]][q[k]]) return 1;
				else vis[q[j]][q[k]] = 1;
			}
		}
	}
	return 0;
}

int main(){
	int i, j, aa, bb, st = 0, fs = inf, k = 40;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++){
		scanf("%d %d", &aa, &bb);
		b[i].x = aa - bb;
		b[i].y = aa + bb;
	}
	for(j = 0; j < m; j++){
		scanf("%d %d", &aa, &bb);
		r[j].x = aa - bb;
		r[j].y = aa + bb;
	}
	sort(b, b + n, cmpb);
	sort(r, r + m, cmpr);
	while(k--){
		aa = (st + fs) / 2;
		if(check(aa)) fs = aa;
		else st = aa;
	}
	if(fs == inf) puts("Poor Sereja!");
	else cout << fs << endl;
}