//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n, a[N], b[N], c[N], buc[N], vis[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
struct Node {
	int cnt, x;
	Node(int a=0, int b=0) : cnt(a), x(b) {}
	~Node() {}
	friend bool operator == (const Node &a, const Node &b) {return a.cnt == b.cnt && a.x == b.x;}
	friend bool operator > (const Node &a, const Node &b) {
		if(a.cnt != b.cnt) return a.cnt > b.cnt;
		return a.x > b.x;
	}
	friend bool operator < (const Node &a, const Node &b) {return !(a == b) && !(a > b);}
};
bool cmp(const Node &a, const Node &b) {return a.x > b.x;}
priority_queue<Node> q;
vector<pair<int, pair<int, int> > > ans;

int main() {
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		c[i] = b[i] = a[i];
	}
	sort(b+1, b+1+n);
	int tot = unique(b+1, b+1+n) - b;
	rep(i, 1, n) c[i] = lower_bound(b+1, b+1+tot, c[i]) - b;
	rep(i, 1, n) ++buc[c[i]];
	rep(i, 1, n) {
		if(vis[c[i]]) continue;
		vis[c[i]] = 1;
		q.push(Node(buc[c[i]], a[i]));
	}
	while(!q.empty()) {
		Node p[3];
		p[0] = q.top(); q.pop();
		if(q.empty()) break;
		p[1] = q.top(); q.pop();
		if(q.empty()) break;
		p[2] = q.top(); q.pop();
		sort(p, p+3, cmp);
		ans.push_back(make_pair(p[0].x, make_pair(p[1].x, p[2].x)));
		rep(i, 0, 2) --p[i].cnt;
		rep(i, 0, 2) if(p[i].cnt) q.push(p[i]);
	}
	int sz = ans.size();
	printf("%d\n", sz);
	rep(i, 0, sz-1) printf("%d %d %d\n", ans[i].first, ans[i].second.first, ans[i].second.second);
    return 0;
}