#include <bits/stdc++.h>

#define eps 1e-7
#define sq(x) ((x)*(x))
#define x1 kakaskakas
#define x2 jmjjmjjmjj
#define y1 spiderspid
#define y2 likolikoli
#define inf 0x3f3f3f3f
using namespace std;

template<class T> inline void smin(T &a, T b) {if(a>b) a=b;}
template<class T> inline void smax(T &a, T b) {if(a<b) a=b;}

#define x first
#define y second
#define NN 1111
typedef pair<int, int> pii;

pii p[NN*11], q[NN*11];
char grid[NN][NN];

pii O;

int sgn(int a) {
	return a<0 ? -1:a>0;
}

pii operator - (pii a, pii b) {
	return pii(a.x-b.x, a.y-b.y);
}

int multi(pii a, pii b) {
	return a.x*b.y-a.y*b.x;
}

int dist(pii a, pii b) {
	return sq(a.x-b.x)+sq(a.y-b.y);
}

bool cmp(pii a, pii b) {
	int t=sgn(multi(a-O, b-O));
	if (t) return t>0;
	return dist(a, O)<dist(b, O);
}

void graham(pii *p, int n, pii *h, int &m) {
	int i;
	if (n<=3) {
		for (i=0; i<n; i++) h[i]=p[i];
		m=n;
		return;
	}
	for (i=1; i<n; i++) {
		if (p[i].y<p[0].y || sgn(p[i].y-p[i].y)==0 && p[i].x<p[0].x) swap(p[i], p[0]);
	}
	O=p[0], sort(p+1, p+n, cmp);
	m=2, h[0]=p[0], h[1]=p[1];
	for (i=2; i<n; i++) {
		while (m>1 && sgn(multi(p[i]-h[m-2], h[m-1]-h[m-2]))>=0) m--;
		h[m++]=p[i];
	}
}

int main() {

	int N, i, j, x, y, np, m;
	while(scanf("%d", &N) && N) {
		for (i=N-1; i>=0; i--) scanf("%s", grid[i]);
		np=0;
		for (i=0; i<N; i++) {
			for (j=0; j<N; j++) {
				if (grid[i][j]!='1') continue;
				x=j, y=i;
				if (i && j) {
					if (grid[i-1][j]>'0' && grid[i-1][j-1]>'0' && grid[i][j-1]>'0') p[np++]=pii(x, y);
				}
				if (i && j<N-1) {
					if (grid[i-1][j]>'0' && grid[i-1][j+1]>'0' && grid[i][j+1]>'0') p[np++]=pii(x+1, y);
				}
				if (i<N-1 && j<N-1) {
					if (grid[i+1][j+1]>'0' && grid[i+1][j]>'0' && grid[i][j+1]>'0') p[np++]=pii(x+1, y+1);
				}
				if (i<N-1 && j) {
					if (grid[i+1][j]>'0' && grid[i+1][j-1]>'0' && grid[i][j-1]>'0') p[np++]=pii(x, y+1);
				}
			}
		}
		
		sort(p, p+np);
		np=unique(p, p+np)-p;
		graham(p, np, q, m);
		if (sgn(multi(q[2]-q[0], q[1]-q[0])<0)) for (i=0; i<m/2; i++) swap(q[i], q[m-1-i]);
		printf("%d\n\n", m);
		int cnt=0;
		pii mid=q[0];
		for (i=1; i<m; i++) {
			if (mid>q[i]) mid=q[i], cnt=i;
		}
		for (i=cnt; i<m; i++) {
			printf("%d %d\n\n", q[i].first, q[i].second);
		}
		for (i=0; i<cnt; i++) {
			printf("%d %d\n\n", q[i].first, q[i].second);
		}
	}

	return 0;
}