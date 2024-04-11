//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5; 

int n, m;
set<int> e[N], S;
vector<int> tmp, ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void bfs(int s) {
	int sz = 1;
	queue<int> q;
	q.push(s);
	S.erase(s);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		tmp.clear();
		for(int v : S) {
			if(e[u].find(v) == e[u].end()) {
				++sz;
				q.push(v);
				tmp.push_back(v);
			}
		}
		for(int i : tmp) S.erase(i);
	}
	ans.push_back(sz);
}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].insert(v);
		e[v].insert(u);
	}
	rep(i, 1, n) S.insert(i);
	rep(i, 1, n) if(S.find(i) != S.end()) bfs(i);
	sort(ans.begin(), ans.end());
	printf("%d\n", (int)ans.size());
	for(int i : ans) printf("%d ", i);
	return 0;
}