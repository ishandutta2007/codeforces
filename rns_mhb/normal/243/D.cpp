#include <stdio.h>
#include <algorithm>

using namespace std;

#define M 1010
#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))
#define inf 1e9

int n, a[M][M], c[M * M], cnt, b[M][M], cc[M * M], bb[M][M], ccnt, e[M][M];
int mn[4*M*M], se[4*M*M];
long long ans;
char s[M * 12];

struct pnt{
	int x, y;
	pnt(int x = 0, int y = 0):x(x), y(y){}
	int operator &(pnt a){return x * a.x + y * a.y;}
	int operator ^(pnt a){return x * a.y - y * a.x;}
}d, q[M*M];

bool cmp(pnt a, pnt b){return e[a.x][a.y] < e[b.x][b.y];}

void push_up(int id){
	mn[id] = Min(mn[id<<1], mn[id<<1|1]);
}

void push_down(int id){
	if(se[id]>0){
		if(se[id<<1] < se[id])se[id<<1] = se[id];
		if(mn[id<<1] < se[id])mn[id<<1] = se[id];
		if(se[id<<1|1] < se[id])se[id<<1|1] = se[id];
		if(mn[id<<1|1] < se[id])mn[id<<1|1] = se[id];
		se[id] = 0;
	}
}

void update(int l, int r, int id, int L, int R, int v){
	if(L<=l && r<=R){
		if(se[id]<v)se[id] = v;
		if(mn[id]<v)mn[id] = v;
		return;
	}
	int md = (l + r) >> 1;
	push_down(id);
	if(L<=md)update(l, md, id<<1, L, R, v);
	if(R>md)update(md+1, r, id<<1|1, L, R, v);
	push_up(id);
}

int get_min(int l, int r, int id, int L, int R){
	if(L<=l && r<=R)return mn[id];
	int md = (l + r)>>1, rt = inf;
	push_down(id);
	if(L<=md){
		int tp = get_min(l, md, id<<1, L, R);
		if(rt>tp)rt = tp;
	}
	if(R>md){
		int tp = get_min(md+1, r, id<<1|1, L, R);
		if(rt>tp)rt = tp;
	}
	push_up(id);
	return rt;
}

int main(){
	scanf("%d %d %d\n",&n, &d.x, &d.y);
	for(int i = 0; i < n; i ++)for(int j = 0; j < n; j ++)scanf("%d\n",&a[i][j]);
	for(int i = 0; i <= n; i ++)for(int j = 0; j <= n; j ++){
		pnt p = pnt(i, j);
		c[cnt++] = d ^ p;
	}
	sort(c, c+cnt); cnt = unique(c, c+cnt) - c;
	for(int i = 0; i <= n; i ++)for(int j = 0; j <= n; j ++){
		pnt p = pnt(i, j);
		b[i][j] = lower_bound(c, c+cnt, d ^ p) - c;
	}
	for(int i = 0; i <= n; i ++)for(int j = 0; j <= n; j ++){
		pnt p = pnt(i, j);
		cc[ccnt++] = d & p;
	}
	sort(cc, cc+ccnt); ccnt = unique(cc, cc+ccnt) - cc;
	for(int i = 0; i <= n; i ++)for(int j = 0; j <= n; j ++){
		pnt p = pnt(i, j);
		bb[i][j] = lower_bound(cc, cc + ccnt, d & p) - cc;
	}
	ccnt = 0;
	for(int i = 0; i < n; i ++)for(int j = 0; j < n; j ++){
		q[ccnt++] = pnt(i, j);
		e[i][j] = Min(bb[i][j], bb[i+1][j+1]);
		if(e[i][j] > bb[i][j+1]) e[i][j] = bb[i][j+1];
		if(e[i][j] > bb[i+1][j]) e[i][j] = bb[i+1][j];
	}
	sort(q, q + ccnt, cmp);
	for(int k = 0; k < ccnt; k ++){
		int i = q[k].x, j = q[k].y;
		int xx = M * M, yy = 0;
		if(xx > b[i][j])xx = b[i][j]; if(yy<b[i][j])yy=b[i][j];
		if(xx>b[i+1][j])xx=b[i+1][j]; if(yy<b[i+1][j])yy=b[i+1][j];
		if(xx>b[i][j+1])xx=b[i][j+1]; if(yy<b[i][j+1])yy=b[i][j+1];
		if(xx>b[i+1][j+1])xx=b[i+1][j+1]; if(yy<b[i+1][j+1])yy=b[i+1][j+1];
		yy--;
		int tp = a[i][j] - get_min(0, cnt-2, 1, xx, yy);
		if(tp>0)ans += tp;
		update(0, cnt-2, 1, xx, yy, a[i][j]);
	}
	printf("%I64d\n",ans);
	return 0;
}