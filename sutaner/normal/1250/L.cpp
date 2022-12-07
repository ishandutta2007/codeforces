#include <bits/stdc++.h>
#define maxr 100000
#define endl 1
#define maxn 200019
#define pii pair<int, int>
#define fi first
#define se second
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
    if (ch == '-') f = 0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
    x = (f) ? x : -x;
}

short int num[maxr];
template <class T> void print(T x, bool f = 0){
    if (!x) {putchar('0'); if (f) putchar('\n'); return;}
    if (x < 0) putchar('-'), x = -x;
    int s = 0;
    while (x) num[++s] = x % 10, x /= 10; 
    per(i, s, 1) putchar('0' + num[i]);
    if (f) putchar('\n');
}
int n, m;

bool vis[maxn];
queue<int> bfs, cl;
set<int> alls;
set<int> s;
map<pii, bool> G;

void BFS(int x){
	vis[x] = 1;
	s.clear();
	for (set<int> :: iterator it = alls.begin(); it != alls.end(); it++) s.insert(*it); 
	bfs.push(x); s.erase(x); alls.erase(x);
	while (!bfs.empty()) {
		int op = bfs.front(); bfs.pop();
		for (set<int> :: iterator it = s.begin(); it != s.end(); it++){
			if (!G[pii(op, *it)]) {
				bfs.push(*it);
				cl.push(*it);
				vis[*it] = 1;
				alls.erase(*it);
			}
		}
		while (!cl.empty()) s.erase(cl.front()), cl.pop(); 
	}
}
int main(){
    scanf("%d%d", &n, &m);
	rep(i, 1, n) alls.insert(i);
	int x, y;
	rep(i, 1, m) scanf("%d%d", &x, &y), G[pii(x, y)] = 1, G[pii(y, x)] = 1;
	int ans = 0;
	rep(i, 1, n) if (!vis[i]) BFS(i), ans++; 
	printf("%d", ans - 1);
    return 0;
}