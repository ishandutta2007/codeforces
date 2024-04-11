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

int qf, qb, q[111111];
int dx[]={0, 1, -1, 0};
int dy[]={-1, 0, 0, 1};
char grid[111][111];
int vst[111][111];
#define beyond(u, v) (u<0 || v<0 || u>=N || v>=M)
int main() {
	int N, M, i, j, uu, vv, u, v, k, cnt=0;
	scanf("%d%d", &N, &M);
	for (i=0; i<N; i++) scanf("%s", grid[i]);
	for (i=0; i<N; i++) {
		for (j=0; j<M; j++) {
			if (grid[i][j]!='B') continue;
			if (vst[i][j]) continue;
			cnt++;
			vst[i][j]=1;
			qf=qb=0;
			q[qb++]=i, q[qb++]=j;
			while (qb>qf) {
				u=q[qf++], v=q[qf++];
				for (k=0; k<4; k++) {
					uu=u+dx[k], vv=v+dy[k];
					if (beyond(uu, vv)) continue;
					if (grid[uu][vv]=='.') continue;
					if (vst[uu][vv]) continue;
					vst[uu][vv]=1;
					q[qb++]=uu, q[qb++]=vv;
				}
			}
		}
	}
	printf("%d\n", cnt);

	return 0;
}