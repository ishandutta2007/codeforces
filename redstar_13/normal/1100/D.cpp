#include<bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;

template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}

#define NN 1111

int X[NN], Y[NN];
int cnt[10];
int flag[NN][NN];

int dx[] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[] = {-1, 0, 1, -1, 0, 1, -1, 1};


int main(){
	auto ok = [&] (int u, int v) {
		printf("%d %d\n", u, v);
		fflush(stdout);
		int st;
		gn(st), gn(u, v);
		if(st == -1 and u == -1 and v == -1) exit(0);
		flag[X[st]][Y[st]] = 0;
		X[st] = u, Y[st] = v;
		flag[u][v] = 1;
	};
	
	auto sign = [&] (const int x) {
		return (x>0)-(x<0);
	};
	
	function<void(pii &, pii)> move_king  = [&] (pii &src, pii tar) {
		if(src == tar) return 0;
		pii p = pii(tar.x-src.x, tar.y-src.y);
		int Dx = 0, Dy = 0;
		for(int i=0; i<8; i++) if(sign(dx[i]) == sign(p.x) and sign(dy[i]) == sign(p.y)) {
			Dx = dx[i], Dy = dy[i];
			break;
		}
		assert(Dx != 0 || Dy != 0);
		src.x += Dx, src.y += Dy;
		if(flag[src.x][src.y]) ok(src.x-Dx, src.y);
		ok(src.x, src.y);
		move_king(src, tar);
	};
	
	pii src;
	gn(src.x, src.y);
	int N = 666;
	pii md = pii(500, 500);
	
	for(int i=1; i<=N; i++) {
		gn(X[i], Y[i]);
		flag[X[i]][Y[i]] = 1;
	}
	
	for(int i=0; i<8; i++) {
		int u = src.x + dx[i];
		int v = src.y + dy[i];
		if(u < 1 || u > 999 || v < 1 || v > 999) continue;
		if(flag[u][v]) continue;
		ok(u, v);
		src = pii(u, v);
		break;
	}
	
	move_king(src, md);
	
	for(int i=1; i<=N; i++) {
		if(X[i] > 500){
			if(Y[i] > 500) cnt[4]++;
			if(Y[i] < 500) cnt[3]++;
		}
		if(X[i] < 500) {
			if(Y[i] > 500) cnt[1]++;
			else cnt[2]++;
		}
	}
	
	int MN = 11111;
	
	for(int i=1; i<=4; i++) MN = min(MN, cnt[i]);
	
	if(MN == cnt[1]) move_king(src, pii(999, 1));
	if(MN == cnt[2]) move_king(src, pii(999, 999));
	if(MN == cnt[3]) move_king(src, pii(1, 999));
	if(MN == cnt[4]) move_king(src, pii(1, 1));
	
}