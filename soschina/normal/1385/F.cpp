#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
const int N = 2e5 + 1;

int t, n, k, u, v, cnt[N], leaf[N], head[N], nxt[N << 1], to[N << 1], eid, ans;
inline void addedge(int u, int v){
	to[eid] = v;
	nxt[eid] = head[u];
	head[u] = eid++;
}

struct node{
	int id, leaf;
	bool operator<(const node &b) const{
		return leaf != b.leaf ? leaf > b.leaf : id < b.id;
	}
	node(int x, int y){
		id = x, leaf = y;
	}
};

set<node> st;

int main(){
	scanf("%d", &t);
	while(t--){
		ans = 0, eid = 1;
		st.clear();
		memset(cnt + 1, 0, sizeof(int) * n);
		memset(leaf + 1, 0, sizeof(int) * n);
		memset(head + 1, 0, sizeof(int) * n);
		scanf("%d%d", &n, &k);
		for(int i = 1; i < n; i++){
			scanf("%d%d", &u, &v);
			addedge(u, v), addedge(v, u);
			cnt[u]++, cnt[v]++;
		}
		for(int i = 1; i <= n; i++)
			if(cnt[i] == 1) leaf[to[head[i]]]++;
		for(int i = 1; i <= n; i++) if(leaf[i])
			st.insert(node(i, leaf[i]));
		while(st.size()){
			int p = st.begin() -> id;
			if(leaf[p] < k) break;
			st.erase(st.begin());
			ans += leaf[p] / k;
			cnt[p] -= leaf[p] - leaf[p] % k;
			leaf[p] %= k;
			if(!cnt[p]) break;
			if(cnt[p] == 1){
				for(int e = head[p]; e; e = nxt[e]) if(cnt[to[e]] > 1){
					st.erase(node(to[e], leaf[to[e]]));
					++leaf[to[e]];
					st.insert(node(to[e], leaf[to[e]]));
					break;
				}
			}else st.insert(node(p, leaf[p]));
		}
		printf("%d\n", ans);
	}
	return 0;
}