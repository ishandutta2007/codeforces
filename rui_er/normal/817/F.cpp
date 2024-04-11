//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
using namespace std;
typedef long long ll;
const ll W = 1e18;

ll n;
struct Node {
	ll l, r;
	mutable ll v;
	Node(ll x, ll y = -1, ll z = 0): l(x), r(y), v(z) {}
	bool operator < (const Node &a) const {return l < a.l;}
};
typedef set<Node>::iterator IT;
set<Node> ODT;
IT split(ll pos) {
	IT it = ODT.lower_bound(Node(pos));
	if(it != ODT.end() && it->l == pos) return it;
	--it;
	ll L = it->l, R = it->r, V = it->v;
	ODT.erase(it);
	ODT.insert(Node(L, pos-1, V));
	return ODT.insert(Node(pos, R, V)).first;
}
void assign_val(ll l, ll r, ll w) {
	IT itR = split(r+1), itL = split(l);
	ODT.erase(itL, itR);
	ODT.insert(Node(l, r, w));
}
void flip(ll l, ll r) {
	IT itR = split(r+1), itL = split(l);
	for(;itL!=itR;itL++) itL->v ^= 1;
}
ll query() {for(IT it=ODT.begin();it!=ODT.end();it++) if(!it->v) return it->l; return 0;}

int main() {
	scanf("%lld", &n);
	ODT.insert(Node(1, W, 0));
	while(n--) {
		ll x, l, r;
		scanf("%lld%lld%lld", &x, &l, &r);
		if(x == 1) assign_val(l, r, 1);
		else if(x == 2) assign_val(l, r, 0);
		else flip(l, r);
		printf("%lld\n", query());
	}
    return 0;
}