//By: Luogu@rui_er(122461).
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const ll N = 1.5e5+5;

ll n;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
struct Node {
	ll w, id;
	Node(ll a=0, ll b=0) : w(a), id(b) {}
	~Node() {}
	friend bool operator < (const Node &a, const Node &b) {
		if(a.w != b.w) return a.w > b.w;
		return a.id > b.id;
	}
};
priority_queue<Node> q;
vector<Node> ans;

int main() {
	scanf("%lld", &n);
	rep(i, 1, n) {
		ll x;
		scanf("%lld", &x);
		q.push(Node(x, i));
	}
	while(!q.empty()) {
		Node u = q.top(); q.pop();
		if(q.empty()) {
			ans.push_back(u);
			break;
		}
		Node v = q.top(); q.pop();
		if(u.w == v.w) q.push(Node(v.w*2, v.id));
		else {
			ans.push_back(u);
			q.push(v);
		}
	}
	sort(ans.begin(), ans.end(), [=](Node a, Node b){return a.id < b.id;});
	ll sz = ans.size();
	printf("%lld\n", sz);
	rep(i, 0, sz-1) printf("%lld%c", ans[i].w, " \n"[i==sz-1]);
	return 0;
}