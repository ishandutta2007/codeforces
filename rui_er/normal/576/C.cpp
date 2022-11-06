// Problem: CF576C Points on Plane
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF576C
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e6+5;

int n, pos[N], L[N], R[N], sz, tot;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
struct Dot {
	int x, y, id;
	friend bool operator < (const Dot& a, const Dot& b) {
		if(pos[a.x] != pos[b.x]) return a.x < b.x;
		return (pos[a.x] & 1) ^ (a.y < b.y);
	}
}a[N];
void initBlock() {
	sz = sqrt(N-5);
	while(++tot) {
		L[tot] = R[tot-1] + 1;
		R[tot] = min(tot*sz, n);
		rep(i, L[tot], R[tot]) pos[i] = tot;
		if(R[tot] == n) break;
	}
}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d%d", &a[i].x, &a[i].y);
		a[i].id = i;
	}
	initBlock();
	sort(a+1, a+1+n);
	rep(i, 1, n) printf("%d%c", a[i].id, " \n"[i==n]);
	return 0;
}