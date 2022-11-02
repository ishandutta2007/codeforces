#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 1010

vector <int> v[8][N];
int id[10], cur, tot, dt[N], dtime, m, n;

struct pnt{
	LL x, y;
	pnt(LL _x = 0, LL _y = 0) : x(_x), y(_y) {}
	pnt operator - (const pnt &a) const { return pnt(x - a.x, y - a.y); }
	LL operator ^ (const pnt &a) const { return x * a.x + y * a.y; }
	LL operator & (const pnt &a) const { return x * a.y - y * a.x; }
	void input(){ scanf("%I64d %I64d", &x, &y); }
}A[10], B[N];

bool on_Segment(const pnt &u, const pnt &v, const pnt &w){
	if( (u - v & v - w) != 0 ) return false;
	return (u - v ^ v - w) > 0;
}

bool check(int x){
	if(tot > m) return false;
	int now = id[tot ++];
	for(auto y : v[now][x]) {
		if(dt[y] != dtime){
			if(!check(y)) return false;
		}
	}
	dt[x] = dtime;
	return true;
}

int main(){
	scanf("%d %d", &m, &n);
	for(int i = 1; i <= m; i ++) A[i].input();
	for(int i = 1; i <= n; i ++) B[i].input();
	for(int i = 1; i <= m; i ++){
		for(int j = 1; j <= n; j ++){
			for(int k = 1; k <= n; k ++) if(k != j){
				if(on_Segment(A[i], B[k], B[j])){
					v[i][j].push_back(k);
					if(v[i][j].size() >= m) break;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++) id[j] = j;
		while(true){
			++ dtime; tot = 1;
			if( check(i) ){ ans ++; break; }
			if(!next_permutation(id + 1, id + m + 1)) break;
		}
	}
	printf("%d\n", ans);
}