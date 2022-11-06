//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int nxt[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Dot {
	int x, y;
	Dot(int a=0, int b=0) : x(a), y(b) {}
	~Dot() {}
	friend bool operator == (const Dot& a, const Dot& b) {return a.x == b.x && a.y == b.y;}
}a[3];
int pw(int x) {return x * x;}
int dis2(const Dot& a, const Dot& b) {return pw(a.x - b.x) + pw(a.y - b.y);}
bool check() {
	if(a[0] == a[1] || a[1] == a[2] || a[0] == a[2]) return 0;
	if(dis2(a[0], a[1]) + dis2(a[1], a[2]) == dis2(a[0], a[2])) return 1;
	if(dis2(a[0], a[1]) + dis2(a[0], a[2]) == dis2(a[1], a[2])) return 1;
	if(dis2(a[0], a[2]) + dis2(a[1], a[2]) == dis2(a[0], a[1])) return 1;
	return 0;
}

int main() {
	rep(i, 0, 2) scanf("%d%d", &a[i].x, &a[i].y);
	if(check()) return puts("RIGHT")&0;
	rep(i, 0, 2) {
		rep(j, 0, 3) {
			a[i].x += nxt[j][0];
			a[i].y += nxt[j][1];
			if(check()) return puts("ALMOST")&0;
			a[i].x -= nxt[j][0];
			a[i].y -= nxt[j][1];
		}
	}
	puts("NEITHER");
	return 0;
}