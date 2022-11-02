#include <stdio.h>
#include <queue>
using namespace std;
const int maxn = 2010;
struct ST{
	int x, y, l, r;
	ST(int _x = 0, int _y = 0, int _l = 0, int _r = 0):x(_x),y(_y),l(_l),r(_r){}
};
int n, m, cnt, vis[maxn][maxn];
char s[maxn][maxn];
queue<ST> q;
bool Check(int x, int y){
	if(x <= 0 || x > n) return false;
	else if(y <= 0 || y > m) return false;
	else if(s[x][y] == '*') return false;
	else return true;
}
void DFS(int x, int y, int l, int r){
	if(vis[x][y]) return;
	cnt += vis[x][y] = true;
	if(Check(x - 1, y)) DFS(x - 1, y, l, r);
	if(Check(x + 1, y)) DFS(x + 1, y, l, r);
	if(Check(x, y - 1) && l) q.push(ST(x, y - 1, l - 1, r));
	if(Check(x, y + 1) && r) q.push(ST(x, y + 1, l, r - 1));
}
int main(){
	scanf("%d%d", &n, &m);
	int x, y; scanf("%d%d", &x, &y);
	int l, r; scanf("%d%d", &l, &r);
	for(int i = 1; i <= n; i++)
		scanf("%s", s[i] + 1);
	q.push(ST(x, y, l, r));
	while(!q.empty()){
		ST u = q.front(); q.pop();
		if(vis[u.x][u.y]) continue;
		DFS(u.x, u.y, u.l, u.r);
	}
	printf("%d\n", cnt);
	return 0;
}