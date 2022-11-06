//Virtual Participation
//Coder:rui_er
//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 1e5+5; 

int n, flg[3], tt, flgg[3], tt2, vis[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
struct Node {
	int id[4];
	Node() {memset(id, 0, sizeof(id));}
	Node(int a, int b, int c) {id[1] = a; id[2] = b; id[3] = c;}
	~Node() {}
	bool find(int x) {rep(i, 1, 3) if(x == id[i]) return 1; return 0;}
}q[N];
vector<Node> buc[N];
vector<int> p;
void dfs(int u, int f) {
	p.push_back(u);
	for(auto e : buc[u]) {
		if(e.find(f)) {
			int v = e.id[1] ^ e.id[2] ^ e.id[3] ^ u ^ f;
			if(!vis[v]) {
				vis[v] = 1;
				dfs(v, u);
				break;
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	rep(i, 1, n-2) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		q[i] = Node(x, y, z);
		buc[x].push_back(q[i]);
		buc[y].push_back(q[i]);
		buc[z].push_back(q[i]);
	}
	rep(i, 1, n) {
		int sz = buc[i].size();
		if(sz == 1) flg[++tt] = i;
		else if(sz == 2) flgg[++tt2] = i;
	}
	p.push_back(flg[1]);
	vis[flg[1]] = 1;
	if(buc[flg[1]][0].find(flgg[1])) {
		vis[flgg[1]] = 1;
		dfs(flgg[1], flg[1]);
	}
	else {
		vis[flgg[2]] = 1;
		dfs(flgg[2], flg[1]);
	}
	for(auto i : p) printf("%d ", i);
	puts("");
	return 0;
}